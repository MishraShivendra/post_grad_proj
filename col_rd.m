function [coll_1,coll_2] = col_rd()
clear all;
close all;
clear variables;
thi = fopen(li,'r');                                                       %'C:/soun/SC1_/S1_S2/S1_S2_1.TXT'
co = 1;
k = 1;
l = 1;
while ~feof(thi)
  if(co)
      coll_1{1,k} = fscanf(thi,'%d',1);
      co = 0;
      k = k+1;
  else
      coll_2{1,k} = fscanf(thi,'%d',1);
      co = 1;
      l = l+1;
  end
  
end
fclose(thi);
plot(coll_1{:});
%subplot(2,1,1),plot(coll_1{:});
%subplot(2,1,2),plot(coll_2{:});
