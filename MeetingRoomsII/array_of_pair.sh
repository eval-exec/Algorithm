#!/bin/bash
set -e
MAXCOUNT=3000
if [[ $# != 0  ]]; then
    re='^[0-9]+$'
    if ! [[ $1 =~ $re  ]] ; then
        echo "error: Not a number" >&2; exit 1
    fi
    MAXCOUNT=$1
fi
count=1


array=()
while [ "$count" -le $MAXCOUNT ]; do
    r=$(od -An -N2 -d < /dev/urandom)
    r=$((r%10))
    now=$r
    now+=','
    r2=$(od -An -N2 -d < /dev/urandom)
    r2=$(($r%10))
    r2=$(($r2+$r+1))
    now+=$r2
    now='['$now']'
    ((count+= 1 ))
    array+=$now',';
done
echo '['${array::-1}']'
