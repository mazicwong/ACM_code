#bash
while true; do
    ./data_maker>tmp.in #出数据
    ./a.out<tmp.in>tmp.out #被测程序
    ./3.out<tmp.in>tmp2.out #正确(暴力)程序
    if diff tmp.out tmp2.out; then #比较两个输出文件
        a=1 #printf "AC\n" #结果相同显示 AC
    elif diff -B -b tmp.out tmp2.out; then
        a=1 #printf "PE\n"
    else
        printf "WA\n" #结果不同显示 WA,并退出
        exit 0
    fi
done
