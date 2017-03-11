#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000
#define M 1000

char buffer[N], scan[N], buff[N], tmpbuf[N];
char id[M], contest_id[M], idx[M], extension[M], link[M];
char check[] = "<pre class=\"prettyprint";

int main(int argc, char *argv[]) {
  FILE *f1 = NULL;
  f1 = fopen("list.txt", "rw+");
  if (f1 == NULL) {
    puts("Necessary files could not be opened, exiting.");
    exit(1);
  }
  buffer[0] = '\0';
  fgets(buffer, N, f1);
  int x = 0;
  for (int i = 0; buffer[i] != '\0'; i++) {
    int j = i;
    int k = 0;
    while (buffer[j] != ',') {
      id[k++] = buffer[j++];
    }
    id[k] = '\0';
    j++;
    k = 0;
    while (buffer[j] != ',') {
      contest_id[k++] = buffer[j++];
    }
    contest_id[k] = '\0';
    j++;
    k = 0;
    while (buffer[j] != ',') {
      idx[k++] = buffer[j++];
    }
    idx[k] = '\0';
    i = j;
    FILE *f2 = NULL;
    sprintf(link, "TmpDirCFCodes/%s", id);
    f2 = fopen(link, "rw+");
    if (f2 == NULL) {
      puts("Necessary files could not be opened, exiting.");
      exit(1);
    }
    k = 0;
    while (fgets(tmpbuf, N, f2)) {
      for (int x = 0; tmpbuf[x] != '\0'; x++) {
        buff[k++] = tmpbuf[x];
      }
    }
    buff[k] = '\0';
    for (int j = 0; buff[j] != '\0'; j++) {
      if (buff[j] == '<') {
        int foo = 0;
        while (buff[j++] == check[foo++]);
        if (check[foo] == '\0') {
          for (; buff[j] != '-'; j++);
          int flag = 1;
          if (buff[j - 1] != 'g') {
            flag = 0;
          }
          int k = 0;
          j++;
          for (; buff[j] != ' '; j++) {
            extension[k++] = buff[j];
          }
          extension[k] = '\0';
          for (; buff[j] != '>'; j++);
          FILE *f3 = NULL;
          if (flag) {
            sprintf(link, "Codes/%s_%s.%s", contest_id, idx, extension);
          } else {
            sprintf(link, "Codes/%s_%s", contest_id, idx);
          }
          f3 = fopen(link, "w");
          if (f3 == NULL) {
            puts("Necessary files could not be opened, exiting.");
            exit(1);
          }
          j++;
          for (; buff[j] != '<'; j++) {
            if (buff[j] == '&') {
              switch (buff[j + 1]) {
                case 'q': fprintf(f3, "\"");
                          j += 5;
                          break;
                case 'a': fprintf(f3, "&");
                          j += 4;
                          break;
                case 'l': fprintf(f3, "<");
                          j += 3;
                          break;
                case 'g': fprintf(f3, ">");
                          j += 3;
                          break;
              }
            } else if (buff[j] == '#') {
              if (buff[j + 1] == '3') {
                fprintf(f3, "\'");
                j += 3;
              } else {
                fprintf(f3, "%c", buff[j]);
              }
            } else {
              fprintf(f3, "%c", buff[j]);
            }
          }
          fclose(f3);
          break;
        }
        j--;
      }
    }
    fclose(f2);
  }
  fclose(f1);
  return 0;
}
