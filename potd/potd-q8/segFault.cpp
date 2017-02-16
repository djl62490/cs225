int main()
{
  int * i = NULL;
  //segfault
  *i = 5;
  return 0;

}
