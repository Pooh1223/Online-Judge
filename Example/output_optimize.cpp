template<class T>
void putint(T ___)
{
  char buf[1000];
  int _=0;
  if(___<0) putchar('-'),___=___*-1;
  do
  {
    buf[_++]='0'+(___%10);
    ___=___/10;
  }while(___>0);
  for(_=_-1;_>=0;_--)
    putchar(buf[_]);
  putchar('\n');  //視情況加入
}