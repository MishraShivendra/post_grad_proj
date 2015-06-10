
% Program Information:
% Author:   Shivendra Mishra
% Program:  This .m file reads data from file and Calculates FFT
% Input:    Link to file
% Ouput:    Genrates file for FFT (No return)
%% opening file

%clear all;
li = 'C:\Users\Shivendra Mishra\Desktop\RELP_ME.TXT';
close all;
clc;
op_fil = 'C:\Users\Shivendra Mishra\Desktop\fft_ME.TXT';
img_nam = strrep(op_fil, 'TXT', 'jpg');
fid = fopen(li,'r');
%val = [fscanf(fid,'%s',1) 
 %      fscanf(fid,'%s',1)];
%display(val);


%% Visualizing content of file
Fs = 8000;                                                                  % Sampling frequency
T = 1/Fs;                                                                   % Sample time
l = find_nol(fid);
display(l);
frewind(fid);                                                                % Length of signal
%% load
                                                                             %'C:/soun/SC1_/S1_S2/S1_S2_1.TXT'
y = fscanf(fid,'%d',[1 inf]);

fclose(fid);



%% copy
h = figure;
%y(1,:) = fscanf(fid,'%d',l);
%display(l);
subplot(2,1,1),plot(y(1,:))
set(gca,'YLim',[0 255])
title('Mic1')
xlabel('No of Samples')
ylabel('Amplitude')
L = size(y,2);
t = (0:L-1)*T;                                                              % Time vector
display(L)                                                                  %display(sprintf('L Now:%d',L))




%% FFT_1
NFFT = 2^nextpow2(L);                                                       % Next power of 2 from length of y
Y = fft(y(1,:),NFFT)/L;
f = Fs/2*linspace(0,1,NFFT/2+1);                                            % Plot single-sided amplitude spectrum.
subplot(2,1,2),plot(f,2*abs(Y(1:NFFT/2+1)))
set(gca,'YLim',[-1 3])
set(gca,'XLim',[0 4000])
title('Single-Sided Amplitude Spectrum of y(t)')
xlabel('Frequency_1 (Hz)')
ylabel('|Y(f)|')
Ampl(1,:) =  2*abs(Y(1:NFFT/2+1));

%% FFT_2


saveas(h,img_nam,'jpg')




%% writng Result to file

op = fopen(op_fil,'w');
for r=1:size(Ampl,2)
   fprintf(op,'%f %f\n',f(1,r),Ampl(1,r));
end
fclose(op);
%subplot(3,1,3),plot(f,Ampl)
%set(gca,'YLim',[-1 1])
%set(gca,'XLim',[200 2000])
















