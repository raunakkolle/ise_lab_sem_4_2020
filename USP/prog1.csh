#!/bin/csh

echo -n "Enter file Name: "
set name = $<

set var1 = `ls -l $name | grep -o ^.`

echo $var1

if(-e $name) then
      echo "$name exists"
      switch($var1)
             case -:
                  echo "$name is a regular file"
                  breaksw
             case t:
                  echo "$name is a directory file"
                  breaksw
             case c:
                  echo "$name is a character device file"
                  breaksw
             case b:
                  echo "$name is a block device file"
                  breaksw
             case l:
                  echo "$name is a symbolic link file"
                  breaksw
             
             default:
                   echo "file name is unrecognizable"
                   breaksw
             endsw
else
    echo "$name does not exist"

endif    
                                       
              
