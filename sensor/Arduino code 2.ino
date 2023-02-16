clear all;clc;
fid = fopen('Cyber data\','glove with gear device.txt','r');
count = 29;
i=1;
while count==29
[A,count] = fscanf(fid, '%s', 3);
[B,count] = fscanf(fid, '%f');
if count==29
    data(i,:)=B';
    i=i+1;
end
end
fclose (fid);
