int main()
{
  int * i = new int(8);
  int * j = new int(2);
  //memory leak
  j = i;

}
