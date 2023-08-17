// #include <iostream>

// // #include <cstdio>
// #include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <bits/stdc++.h>

#define BLK_SIZE (64 * 1024)
#define WRITE_SIZE (25)
// #define TARGET_SIZE (1024 * 1024 * 1024 * 1)
#define TARGET_SIZE (1024 * 1)

using namespace std;

typedef struct stmt_s stmt_t;
typedef struct stmt_s {
  int idx;
  char buf[WRITE_SIZE];
};

void filewriteTest1() {
  stmt_t stmt;
  unsigned long long file_offset;
  unsigned long long blk_offset;
  char blk[BLK_SIZE];
  char null_blk[BLK_SIZE] = {'\0', };
  size_t sz = sizeof(stmt_t);

  file_offset = 0;
  blk_offset = 0;

  stmt.idx = 0;
  for (int i = 0; i < sizeof(stmt.buf); i++) {
    stmt.buf[i] = 'a' + (i%13);
  }

  int fd = open("filewriteTest1", O_WRONLY | O_CREAT | O_TRUNC);
  while (file_offset < TARGET_SIZE) {
    stmt.idx += 1;
    memcpy(blk + blk_offset, &sz, sizeof(int));
    blk_offset += sizeof(int);
    memcpy(blk + blk_offset, &stmt, sizeof(stmt_t));
    blk_offset += sizeof(stmt_t);

    if ((blk_offset + sizeof(int) + sizeof(stmt_t)) > BLK_SIZE) {
      write(fd, blk, blk_offset);
      write(fd, null_blk, BLK_SIZE - blk_offset);
      blk_offset = 0;
      file_offset += BLK_SIZE;
    }
  }

  if (blk_offset != 0) {
    write(fd, blk, blk_offset);
    write(fd, null_blk, BLK_SIZE - blk_offset);
    blk_offset = 0;
    file_offset += BLK_SIZE;
    // printf("file_offset: %ull\n", file_offset);
  }
  close(fd);

  printf("%d\n", stmt.idx);
}

void filewriteTest2() {
  stmt_t stmt;
  unsigned long long file_offset = 0;
  unsigned long long blk_offset = 0;
  char null_blk[BLK_SIZE] = {'\0', };
  size_t sz = sizeof(stmt_t);

  stmt.idx = 0;
  for (int i = 0; i < sizeof(stmt.buf); i++) {
    stmt.buf[i] = 'a' + (i%13);
  }

  int fd = open("filewriteTest2", O_WRONLY | O_CREAT | O_TRUNC);
  while (file_offset < TARGET_SIZE) {
    stmt.idx += 1;
    write(fd, &sz, sizeof(int));
    blk_offset += sizeof(int);
    file_offset += sizeof(int);
    write(fd, &stmt, sizeof(stmt_t));
    blk_offset += sizeof(stmt_t);
    file_offset += sizeof(stmt_t);

    if ((blk_offset + sizeof(int) + sizeof(stmt_t)) > BLK_SIZE) {
      write(fd, null_blk, BLK_SIZE - blk_offset);
      file_offset += (BLK_SIZE - blk_offset);
      blk_offset = 0;
    }
  }
  if (blk_offset != 0) {
    write(fd, null_blk, BLK_SIZE - blk_offset);
    file_offset += (BLK_SIZE - blk_offset);
    blk_offset = 0;
  }

  close(fd);
  printf("%d\n", stmt.idx);
}

int main(void) {
  remove("filewriteTest1");
  remove("filewriteTest2");

  time_t start1 = time(NULL);
  filewriteTest1();
  time_t end1 = time(NULL);

  time_t start2 = time(NULL);
  filewriteTest2();
  time_t end2 = time(NULL);

  printf("filewriteTest1 cost: %lf\n", (double)(end1 - start1));
  printf("filewriteTest2 cost: %lf\n", (double)(end2 - start2));

  struct stat st;

  stat("", &st);
  printf("st.blk_size: %d\n", st.st_blksize);

  return 0;
}