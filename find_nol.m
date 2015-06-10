function n = find_nol(fids)
n = 0;
tline = fgetl(fids);
while ischar(tline)
  tline = fgetl(fids);
  n = n+1;
end
