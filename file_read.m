function file_read(li)
% Program Information:
% Author:   Shivendra Mishra
% Program:  This .m file reads data from file and Calculates FFT
% Input:    Link to file
% Ouput:    Genrates file for FFT (No return)
%% opening file

%clear all;
clearvars -except li;
close all;
clc;
op_fil = strrep(li, 'soun', 'fft');
img_nam = strrep(op_fil, 'TXT', 'jpg');
fid = fopen(li,'r');
%val = [fscanf(fid,'%s',1) 
 %      fscanf(fid,'%s',1)];
%display(val);


%% Visualizing content of file
Fs = 4000;                                                                  % Sampling frequency
T = 1/Fs;                                                                   % Sample time
l = find_nol(fid);
display(l);
frewind(fid);                                                                % Length of signal
%% load
                                                                             %'C:/soun/SC1_/S1_S2/S1_S2_1.TXT'
y = fscanf(fid,'%d %d',[2 inf]);

fclose(fid);



%% copy
h = figure;
%y(1,:) = fscanf(fid,'%d',l);
%display(l);
subplot(4,1,1),plot(y(1,:))
set(gca,'YLim',[0 255])
title('Mic1')
xlabel('No of Samples')
ylabel('Amplitude')
subplot(4,1,2),plot(y(2,:))
set(gca,'YLim',[0 255])
title('Mic2')
xlabel('No of Samples')
ylabel('Amplitude')
L = size(y,2);
t = (0:L-1)*T;                                                              % Time vector
display(L)                                                                  %display(sprintf('L Now:%d',L))




%% FFT_1
NFFT = 2^nextpow2(L);                                                       % Next power of 2 from length of y
Y = fft(y(1,:),NFFT)/L;
f = Fs/2*linspace(0,1,NFFT/2+1);                                            % Plot single-sided amplitude spectrum.
subplot(4,1,3),plot(f,2*abs(Y(1:NFFT/2+1)))
set(gca,'YLim',[-1 1])
set(gca,'XLim',[0 2000])
title('Single-Sided Amplitude Spectrum of y(t)')
xlabel('Frequency_1 (Hz)')
ylabel('|Y(f)|')
Ampl(1,:) =  2*abs(Y(1:NFFT/2+1));

%% FFT_2

NFFT_1 = 2^nextpow2(L);                                                       % Next power of 2 from length of y
Y_1 = fft(y(2,:),NFFT_1)/L;
f_1 = Fs/2*linspace(0,1,NFFT_1/2+1);                                            % Plot single-sided amplitude spectrum.
subplot(4,1,4),plot(f_1,2*abs(Y_1(1:NFFT_1/2+1)))
set(gca,'YLim',[-1 1])
set(gca,'XLim',[0 2000])
title('Single-Sided Amplitude Spectrum of y(t)')
xlabel('Frequency_2 (Hz)')
ylabel('|Y(f)|')
saveas(h,img_nam,'jpg')
Ampl_1(1,:) =  2*abs(Y(1:NFFT_1/2+1));




%% writng Result to file

op = fopen(op_fil,'w');
for r=1:size(Ampl,2)
   fprintf(op,'%f %f %f %f\n',f(1,r),Ampl(1,r),f_1(1,r),Ampl_1(1,r));
end
fclose(op);
%subplot(3,1,3),plot(f,Ampl)
%set(gca,'YLim',[-1 1])
%set(gca,'XLim',[200 2000])
















