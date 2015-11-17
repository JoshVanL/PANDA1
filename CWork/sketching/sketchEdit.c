#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "display.h"

const int DX = 0;
const int DY = 1;
const int DT = 2;
const int PEN = 3;

struct state {
  int xPos;
  int yPos;
  int newXPos;
  int newYPos;
  bool penUp;
  int lastCall;
  int colour;
};

int opcode(int n){
  return ((n >> 6) & 0x03);
}

int operand(int n){
  int j;
  j = 0;
  if (((n >> 5) & 0x1) == 0x1){
    for (int x = 0; x < 6; x++){
      if (((n >> x) & 0x1) == 0x0){
        j = j + (pow (2, x));
      }
    }
    return ~j;
  }
  return (n & 0x3F);
}

struct state moveX (display *d, struct state s, int n) {
s.newXPos = s.newXPos + n;
s.lastCall = 0;
return s;
}

struct state moveY(display *d, struct state s, int n) {
s.newYPos = s.newYPos + n;
s.lastCall = 1;
return s;
}

struct state penDraw(display *d, struct state s) {
  s.penUp = ! s.penUp;
  if (s.penUp == true && (s.lastCall != 2 || s.lastCall != 3)){
    if (s.colour == -1){
      line(d, s.xPos, s.yPos, s.newXPos, s.newYPos);
    } else{
      cline(d, s.xPos, s.yPos, s.newXPos, s.newYPos, s.colour);
    }
  }
  s.xPos = s.newXPos;
  s.yPos = s.newYPos;
  s.lastCall = 3;
  return s;
}

struct state wait(display *d, int n, struct state s){
  if (s.lastCall != 3 && s.lastCall != 2) {
    if (s.colour == -1){
      line(d, s.xPos, s.yPos, s.newXPos, s.newYPos);
    } else{
      cline(d, s.xPos, s.yPos, s.newXPos, s.newYPos, s.colour);
    }

    s.xPos = s.newXPos;
    s.yPos = s.newYPos;
  }
  s.lastCall = 2;
  pause(d, n);
  return s;
}

struct state clearDisplay(display *d, struct state s){
  s.penUp = true;
  s.lastCall = 4;
  clear(d);
  return s;
}

struct state colour(struct state s, int red, int green, int blue, int opacity) {
  if (red < 0){
    red = s.colour >> 24 & 0xFF;
  } else{
    red = red & 0xFF;
  }

  if (green < 0){
    green = s.colour >> 16 & 0xFF;
  } else {
    green = green & 0xFF;
  }

  if (blue < 0){
    blue = s.colour >> 8 & 0xFF;
  } else {
    blue = blue & 0xFF;
  }

  if (opacity < 0){
    opacity = s.colour >> 0 & 0xFF;
  } else {
    opacity = opacity & 0xFF;
  }
  s.colour = (red << 24) + (green << 16) + (blue << 8) + (opacity);
  return s;
}

struct state executeCommand(display *d, struct state s, int opc, int opr){
  switch (opc) {
    case 0:
    s = moveX(d, s, opr);
    break;
    case 1:
    s = moveY(d, s, opr);
    break;
    case 2:
    s = wait(d, opr, s);
    break;
    case 3:
    s = penDraw(d, s);
    break;
    case 4:
    s = clearDisplay(d, s);
    break;
    case 5:
    key(d);
    break;
    case 6:
    s = colour(s, opr, -1, -1, -1);
    break;
    case 7:
    s = colour(s, -1, opr, -1, -1);
    break;
    case 8:
    s = colour(s, -1, -1, opr, -1);
    break;
    case 9:
    s = colour(s, -1, -1, -1, opr);
    break;
  }
  return s;
}


void interpret(FILE *in, display *d) {
  struct state s;
  s.xPos = 0;
  s.yPos = 0;
  s.newXPos = 0;
  s.newYPos = 0;
  s.penUp = true;
  s.lastCall = 3;
  s.colour = -1;
  unsigned char b;
  bool inputCon = false;
  bool first = true;
  int opc;
  int opr;
  while( ! feof(in)){
    b = fgetc(in);
    if (inputCon == false) {
      opc = b >> 6;

      if (opc != 3) {
        opr = b & 0x3f;

        if (opc != 2 && (opr & 0x20) != 0) {
          opr = (-1 << 6) | opr;
        }

        s = executeCommand(d, s, opc, opr);
      } else{
        opc = b & 0x1f;
        opr = 0;

        if ((b & 0x20) == 0) {
          s = executeCommand(d, s, opc, opr);
        } else {
          inputCon = true;
          first = true;
        }
      }
    } else {
      inputCon = b >> 7;

      if (first) {
        opr = (b & 0x40) != 0 ? -1 : 0;
        first = false;
      }

      opr = (opr << 7) | (b & 0x7f);

      if (inputCon == false) {
        s = executeCommand (d, s, opc, opr);
      }
    }
  }
}

// TODO: upgrade this function to read instructions from the file and obey them
void run(char *filename, bool testing) {
  FILE *in = fopen(filename, "rb");
  if (in == NULL) {
    printf("Can't open %s\n", filename);
    exit(1);
  }
  display *d = newDisplay(filename, 200, 200, testing);
  interpret(in, d);
  end(d);
  fclose(in);
  if (testing) printf("Sketch %s OK\n", filename);
}

// ----------------------------------------------------------------------------
// Nothing below this point needs to be changed.
// ----------------------------------------------------------------------------

void testSketches() {
  // Stage 1
  run("line.sketch", true);
  run("square.sketch", true);
  run("box.sketch", true);
  run("oxo.sketch", true);

  // Stage 2
  run("diag.sketch", true);
  run("cross.sketch", true);

  // Stage 3
  run("clear.sketch", true);
  run("key.sketch", true);

  // Stage 4
  run("pauses.sketch", true);
  run("field.sketch", true);
  run("lawn.sketch", true);
}

int main(int n, char *args[n]) {
  if (n == 1) testSketches();
  else if (n == 2) run(args[1], false);
  else {
    fprintf(stderr, "Usage: sketch [file.sketch]");
    exit(1);
  }
}
