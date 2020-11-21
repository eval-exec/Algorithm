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

    incount=$(od -An -N2 -d < /dev/urandom)
    incount=$((incount%5+1))


    i=0
    now=""
    while [ "$i" -le  $incount ];do
        r=$(od -An -N2 -d < /dev/urandom)
        r=$((r%2))
        n=$((n+r))
        ((i+=1))
        now+=$n,
    done
    now=${now::-1}
    now='['$now']'
    array+=$now',';


    ((count+= 1 ))
done

echo '['${array::-1}']'
