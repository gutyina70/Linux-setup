// sudo make install && killall -q dwmblocks; dwmblocks &
static char totalMemory[] = "free | awk '/^Mem/ { printf \"%.1f%\", $3 / $2 * 100 }'";
static char focusedMemory[] =
"win=`xdotool getactivewindow`;"
"if [ $? -eq 0 ]; then" // if there is an active window
"  pid=`xdotool getwindowpid $win`;"
"  name=`ps u -p $pid | tail -n 1 | awk '{ n = split($11, path, \"/\"); print path[n] }';`"
"  mem_arr=`ps ux | grep $name | awk '{ print $6 }'`;"
"  mem=0; for i in $mem_arr; do mem=`expr $mem + $i`; done;"
"  mem_max=`free -k | awk '/^Mem/ { print $2 }'`;"
"  echo $name $mem $mem_max | awk '{ printf \"%s Mem: %.1f%\", $1, $2 / $3 * 100 }';"
"fi";
static char date[] = "date '+%m-%d %H:%M:%S'";

static const Block blocks[] = {
  /* Icon            Command         Update Interval (100ms)    Update Signal */
  {  "Total Mem: "  ,totalMemory    ,10                        ,0 },
  {  ""             ,focusedMemory  ,1                         ,0 },
  {  ""             ,date           ,1                         ,0 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char* delim = " | ";
static unsigned int delimLen = 3;
