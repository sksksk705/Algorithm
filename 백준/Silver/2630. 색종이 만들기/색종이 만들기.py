import sys

WHITE = 0;
BLUE = 1;
white_paper = 0
blue_paper = 0
paper = [];

def check_same_color(x, y, n):
  color = paper[x][y]
  for i in range(x,x+ n):
    for j in range(y,y+n):
      if (paper[i][j] != color):
        return False
  return True


def cut_paper(x, y, n):
  global WHITE,BLUE,white_paper,blue_paper
  color = paper[x][y]
  if (check_same_color(x, y, n)):
    if (color == WHITE):
      white_paper += 1
    elif (color == BLUE):
      blue_paper+=1
    return

  cut_length = int(n/2)
  cut_paper(x, y,cut_length);
  cut_paper(x+cut_length, y,cut_length);
  cut_paper(x, y + cut_length, cut_length);
  cut_paper(x + cut_length, y + cut_length, cut_length);


n = int(sys.stdin.readline())

for i in range(n):
  paper.append(list(map(int,sys.stdin.readline().split())))

cut_paper(0, 0, n);

print(white_paper)
print(blue_paper)