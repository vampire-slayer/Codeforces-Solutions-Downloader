wget http://codeforces.com/api/user.status?handle=$1
mv user.status?handle=$1 codeforces.txt
mkdir TmpDirCFCodes
cc parser.c
./a.out
cd TmpDirCFCodes
wget -i download.txt
cd ..
mkdir Codes
cc fix.c
./a.out
rm codeforces.txt
rm TmpDirCFCodes/download.txt
rm list.txt
rm -rf TmpDirCFCodes
rm a.out
