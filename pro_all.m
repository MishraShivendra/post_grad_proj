%% Processing audio sample files for fft
  clear all;
  clearvars;
  close all;
  clc;
  links(1).ip = 'C:/soun/SC1_/S1_S2/S1_S2_1.TXT';   
  links(2).ip = 'C:/soun/SC1_/S1_S2/S1_S2_2.TXT';
  links(3).ip = 'C:/soun/SC1_/S1_S2/S1_S2_3.TXT';
  links(4).ip = 'C:/soun/SC1_/S1_S2/S1_S2_4.TXT';
  links(5).ip = 'C:/soun/SC1_/S1_S2/S1_S2_5.TXT';
  links(6).ip = 'C:/soun/SC1_/S1_S2/S1_S2_6.TXT';
  links(7).ip = 'C:/soun/SC1_/S1_S2/S1_S2_7.TXT';
  links(8).ip = 'C:/soun/SC1_/S1_S2/S1_S2_8.TXT';
  links(9).ip = 'C:/soun/SC1_/S1_S2/S1_S2_9.TXT';
  links(10).ip = 'C:/soun/SC1_/S1_S2/S1_S2_10.TXT';
  links(11).ip = 'C:/soun/SC1_/S2_S1/S2_S1_1.TXT';
  links(12).ip = 'C:/soun/SC1_/S2_S1/S2_S1_2.TXT';
  links(13).ip = 'C:/soun/SC1_/S2_S1/S2_S1_3.TXT';
  links(14).ip = 'C:/soun/SC1_/S2_S1/S2_S1_4.TXT';
  links(15).ip = 'C:/soun/SC1_/S2_S1/S2_S1_5.TXT';
  links(16).ip = 'C:/soun/SC1_/S2_S1/S2_S1_6.TXT';
  links(17).ip = 'C:/soun/SC1_/S2_S1/S2_S1_7.TXT';
  links(18).ip = 'C:/soun/SC1_/S2_S1/S2_S1_8.TXT';
  links(19).ip = 'C:/soun/SC1_/S2_S1/S2_S1_9.TXT';
  links(20).ip = 'C:/soun/SC1_/S2_S1/S2_S1_10.TXT';
  links(21).ip = 'C:/soun/SC1_/S3_S4/S3_S4_1.TXT';
  links(22).ip = 'C:/soun/SC1_/S3_S4/S3_S4_2.TXT';
  links(23).ip = 'C:/soun/SC1_/S3_S4/S3_S4_3.TXT';
  links(24).ip = 'C:/soun/SC1_/S3_S4/S3_S4_4.TXT';
  links(25).ip = 'C:/soun/SC1_/S3_S4/S3_S4_5.TXT';
  links(26).ip = 'C:/soun/SC1_/S3_S4/S3_S4_6.TXT';
  links(27).ip = 'C:/soun/SC1_/S3_S4/S3_S4_7.TXT';
  links(28).ip = 'C:/soun/SC1_/S3_S4/S3_S4_8.TXT';
  links(29).ip = 'C:/soun/SC1_/S3_S4/S3_S4_9.TXT';
  links(30).ip = 'C:/soun/SC1_/S3_S4/S3_S4_10.TXT';
  links(31).ip = 'C:/soun/SC1_/S4_S3/S4_S3_1.TXT';
  links(32).ip = 'C:/soun/SC1_/S4_S3/S4_S3_2.TXT';
  links(33).ip = 'C:/soun/SC1_/S4_S3/S4_S3_3.TXT';
  links(34).ip = 'C:/soun/SC1_/S4_S3/S4_S3_4.TXT';
  links(35).ip = 'C:/soun/SC1_/S4_S3/S4_S3_5.TXT';
  links(36).ip = 'C:/soun/SC1_/S4_S3/S4_S3_6.TXT';
  links(37).ip = 'C:/soun/SC1_/S4_S3/S4_S3_7.TXT';
  links(38).ip = 'C:/soun/SC1_/S4_S3/S4_S3_8.TXT';
  links(39).ip = 'C:/soun/SC1_/S4_S3/S4_S3_9.TXT';
  links(40).ip = 'C:/soun/SC1_/S4_S3/S4_S3_10.TXT';
  links(41).ip = 'C:/soun/SC1_/S5_S6/S5_S6_1.TXT';
  links(42).ip = 'C:/soun/SC1_/S5_S6/S5_S6_2.TXT';
  links(43).ip = 'C:/soun/SC1_/S5_S6/S5_S6_3.TXT';
  links(44).ip = 'C:/soun/SC1_/S5_S6/S5_S6_4.TXT';
  links(45).ip = 'C:/soun/SC1_/S5_S6/S5_S6_5.TXT';
  links(46).ip = 'C:/soun/SC1_/S5_S6/S5_S6_6.TXT';
  links(47).ip = 'C:/soun/SC1_/S5_S6/S5_S6_7.TXT';
  links(48).ip = 'C:/soun/SC1_/S5_S6/S5_S6_8.TXT';
  links(49).ip = 'C:/soun/SC1_/S5_S6/S5_S6_9.TXT';
  links(50).ip = 'C:/soun/SC1_/S5_S6/S5_S6_10.TXT';
  links(51).ip = 'C:/soun/SC1_/S6_S5/S6_S5_1.TXT';
  links(52).ip = 'C:/soun/SC1_/S6_S5/S6_S5_2.TXT';
  links(53).ip = 'C:/soun/SC1_/S6_S5/S6_S5_3.TXT';
  links(54).ip = 'C:/soun/SC1_/S6_S5/S6_S5_4.TXT';
  links(55).ip = 'C:/soun/SC1_/S6_S5/S6_S5_5.TXT';
  links(56).ip = 'C:/soun/SC1_/S6_S5/S6_S5_6.TXT';
  links(57).ip = 'C:/soun/SC1_/S6_S5/S6_S5_7.TXT';
  links(58).ip = 'C:/soun/SC1_/S6_S5/S6_S5_8.TXT';
  links(59).ip = 'C:/soun/SC1_/S6_S5/S6_S5_9.TXT';
  links(60).ip = 'C:/soun/SC1_/S6_S5/S6_S5_10.TXT';
  links(61).ip = 'C:/soun/SC1_/S7_S8/S7_S8_1.TXT';
  links(62).ip = 'C:/soun/SC1_/S7_S8/S7_S8_2.TXT';
  links(63).ip = 'C:/soun/SC1_/S7_S8/S7_S8_3.TXT';
  links(64).ip = 'C:/soun/SC1_/S7_S8/S7_S8_4.TXT';
  links(65).ip = 'C:/soun/SC1_/S7_S8/S7_S8_5.TXT';
  links(66).ip = 'C:/soun/SC1_/S7_S8/S7_S8_6.TXT';
  links(67).ip = 'C:/soun/SC1_/S7_S8/S7_S8_7.TXT';
  links(68).ip = 'C:/soun/SC1_/S7_S8/S7_S8_8.TXT';
  links(69).ip = 'C:/soun/SC1_/S7_S8/S7_S8_9.TXT';
  links(70).ip = 'C:/soun/SC1_/S7_S8/S7_S8_10.TXT';
  links(71).ip = 'C:/soun/SC1_/S8_S7/S8_S7_1.TXT';
  links(72).ip = 'C:/soun/SC1_/S8_S7/S8_S7_2.TXT';
  links(73).ip = 'C:/soun/SC1_/S8_S7/S8_S7_3.TXT';
  links(74).ip = 'C:/soun/SC1_/S8_S7/S8_S7_4.TXT';
  links(75).ip = 'C:/soun/SC1_/S8_S7/S8_S7_5.TXT';
  links(76).ip = 'C:/soun/SC1_/S8_S7/S8_S7_6.TXT';
  links(77).ip = 'C:/soun/SC1_/S8_S7/S8_S7_7.TXT';
  links(78).ip = 'C:/soun/SC1_/S8_S7/S8_S7_8.TXT';
  links(79).ip = 'C:/soun/SC1_/S8_S7/S8_S7_9.TXT';
  links(80).ip = 'C:/soun/SC1_/S8_S7/S8_S7_10.TXT';
  links(81).ip = 'C:/soun/SC2_/S1_S2/S1_S2_1.TXT';
  links(82).ip = 'C:/soun/SC2_/S1_S2/S1_S2_2.TXT';
  links(83).ip = 'C:/soun/SC2_/S1_S2/S1_S2_3.TXT';
  links(84).ip = 'C:/soun/SC2_/S1_S2/S1_S2_4.TXT';
  links(85).ip = 'C:/soun/SC2_/S1_S2/S1_S2_5.TXT';
  links(86).ip = 'C:/soun/SC2_/S1_S2/S1_S2_6.TXT';
  links(87).ip = 'C:/soun/SC2_/S1_S2/S1_S2_7.TXT';
  links(88).ip = 'C:/soun/SC2_/S1_S2/S1_S2_8.TXT';
  links(89).ip = 'C:/soun/SC2_/S1_S2/S1_S2_9.TXT';
  links(90).ip = 'C:/soun/SC2_/S1_S2/S1_S2_10.TXT';
  links(91).ip = 'C:/soun/SC2_/S2_S1/S2_S1_1.TXT';
  links(92).ip = 'C:/soun/SC2_/S2_S1/S2_S1_2.TXT';
  links(93).ip = 'C:/soun/SC2_/S2_S1/S2_S1_3.TXT';
  links(94).ip = 'C:/soun/SC2_/S2_S1/S2_S1_4.TXT';
  links(95).ip = 'C:/soun/SC2_/S2_S1/S2_S1_5.TXT';
  links(96).ip = 'C:/soun/SC2_/S2_S1/S2_S1_6.TXT';
  links(97).ip = 'C:/soun/SC2_/S2_S1/S2_S1_7.TXT';
  links(98).ip = 'C:/soun/SC2_/S2_S1/S2_S1_8.TXT';
  links(99).ip = 'C:/soun/SC2_/S2_S1/S2_S1_9.TXT';
  links(100).ip = 'C:/soun/SC2_/S2_S1/S2_S1_10.TXT';
  links(101).ip = 'C:/soun/SC2_/S3_S4/S3_S4_1.TXT';
  links(102).ip = 'C:/soun/SC2_/S3_S4/S3_S4_2.TXT';
  links(103).ip = 'C:/soun/SC2_/S3_S4/S3_S4_3.TXT';
  links(104).ip = 'C:/soun/SC2_/S3_S4/S3_S4_4.TXT';
  links(105).ip = 'C:/soun/SC2_/S3_S4/S3_S4_5.TXT';
  links(106).ip = 'C:/soun/SC2_/S3_S4/S3_S4_6.TXT';
  links(107).ip = 'C:/soun/SC2_/S3_S4/S3_S4_7.TXT';
  links(108).ip = 'C:/soun/SC2_/S3_S4/S3_S4_8.TXT';
  links(109).ip = 'C:/soun/SC2_/S3_S4/S3_S4_9.TXT';
  links(110).ip = 'C:/soun/SC2_/S3_S4/S3_S4_10.TXT';
  links(111).ip = 'C:/soun/SC2_/S4_S3/S4_S3_1.TXT';
  links(112).ip = 'C:/soun/SC2_/S4_S3/S4_S3_2.TXT';
  links(113).ip = 'C:/soun/SC2_/S4_S3/S4_S3_3.TXT';
  links(114).ip = 'C:/soun/SC2_/S4_S3/S4_S3_4.TXT';
  links(115).ip = 'C:/soun/SC2_/S4_S3/S4_S3_5.TXT';
  links(116).ip = 'C:/soun/SC2_/S4_S3/S4_S3_6.TXT';
  links(117).ip = 'C:/soun/SC2_/S4_S3/S4_S3_7.TXT';
  links(118).ip = 'C:/soun/SC2_/S4_S3/S4_S3_8.TXT';
  links(119).ip = 'C:/soun/SC2_/S4_S3/S4_S3_9.TXT';
  links(120).ip = 'C:/soun/SC2_/S4_S3/S4_S3_10.TXT';
  links(121).ip = 'C:/soun/SC2_/S5_S6/S5_S6_1.TXT';
  links(122).ip = 'C:/soun/SC2_/S5_S6/S5_S6_2.TXT';
  links(123).ip = 'C:/soun/SC2_/S5_S6/S5_S6_3.TXT';
  links(124).ip = 'C:/soun/SC2_/S5_S6/S5_S6_4.TXT';
  links(125).ip = 'C:/soun/SC2_/S5_S6/S5_S6_5.TXT';
  links(126).ip = 'C:/soun/SC2_/S5_S6/S5_S6_6.TXT';
  links(127).ip = 'C:/soun/SC2_/S5_S6/S5_S6_7.TXT';
  links(128).ip = 'C:/soun/SC2_/S5_S6/S5_S6_8.TXT';
  links(129).ip = 'C:/soun/SC2_/S5_S6/S5_S6_9.TXT';
  links(130).ip = 'C:/soun/SC2_/S5_S6/S5_S6_10.TXT';
  links(131).ip = 'C:/soun/SC2_/S6_S5/S6_S5_1.TXT';
  links(132).ip = 'C:/soun/SC2_/S6_S5/S6_S5_2.TXT';
  links(133).ip = 'C:/soun/SC2_/S6_S5/S6_S5_3.TXT';
  links(134).ip = 'C:/soun/SC2_/S6_S5/S6_S5_4.TXT';
  links(135).ip = 'C:/soun/SC2_/S6_S5/S6_S5_5.TXT';
  links(136).ip = 'C:/soun/SC2_/S6_S5/S6_S5_6.TXT';
  links(137).ip = 'C:/soun/SC2_/S6_S5/S6_S5_7.TXT';
  links(138).ip = 'C:/soun/SC2_/S6_S5/S6_S5_8.TXT';
  links(139).ip = 'C:/soun/SC2_/S6_S5/S6_S5_9.TXT';
  links(140).ip = 'C:/soun/SC2_/S6_S5/S6_S5_10.TXT';
  links(141).ip = 'C:/soun/SC2_/S7_S8/S7_S8_1.TXT';
  links(142).ip = 'C:/soun/SC2_/S7_S8/S7_S8_2.TXT';
  links(143).ip = 'C:/soun/SC2_/S7_S8/S7_S8_3.TXT';
  links(144).ip = 'C:/soun/SC2_/S7_S8/S7_S8_4.TXT';
  links(145).ip = 'C:/soun/SC2_/S7_S8/S7_S8_5.TXT';
  links(146).ip = 'C:/soun/SC2_/S7_S8/S7_S8_6.TXT';
  links(147).ip = 'C:/soun/SC2_/S7_S8/S7_S8_7.TXT';
  links(148).ip = 'C:/soun/SC2_/S7_S8/S7_S8_8.TXT';
  links(149).ip = 'C:/soun/SC2_/S7_S8/S7_S8_9.TXT';
  links(150).ip = 'C:/soun/SC2_/S7_S8/S7_S8_10.TXT';
  links(151).ip = 'C:/soun/SC2_/S8_S7/S8_S7_1.TXT';
  links(152).ip = 'C:/soun/SC2_/S8_S7/S8_S7_2.TXT';
  links(153).ip = 'C:/soun/SC2_/S8_S7/S8_S7_3.TXT';
  links(154).ip = 'C:/soun/SC2_/S8_S7/S8_S7_4.TXT';
  links(155).ip = 'C:/soun/SC2_/S8_S7/S8_S7_5.TXT';
  links(156).ip = 'C:/soun/SC2_/S8_S7/S8_S7_6.TXT';
  links(157).ip = 'C:/soun/SC2_/S8_S7/S8_S7_7.TXT';
  links(158).ip = 'C:/soun/SC2_/S8_S7/S8_S7_8.TXT';
  links(159).ip = 'C:/soun/SC2_/S8_S7/S8_S7_9.TXT';
  links(160).ip = 'C:/soun/SC2_/S8_S7/S8_S7_10.TXT';
  links(161).ip = 'C:/soun/SC3_/S1_S2/S1_S2_1.TXT';
  links(162).ip = 'C:/soun/SC3_/S1_S2/S1_S2_2.TXT';
  links(163).ip = 'C:/soun/SC3_/S1_S2/S1_S2_3.TXT';
  links(164).ip = 'C:/soun/SC3_/S1_S2/S1_S2_4.TXT';
  links(165).ip = 'C:/soun/SC3_/S1_S2/S1_S2_5.TXT';
  links(166).ip = 'C:/soun/SC3_/S1_S2/S1_S2_6.TXT';
  links(167).ip = 'C:/soun/SC3_/S1_S2/S1_S2_7.TXT';
  links(168).ip = 'C:/soun/SC3_/S1_S2/S1_S2_8.TXT';
  links(169).ip = 'C:/soun/SC3_/S1_S2/S1_S2_9.TXT';
  links(170).ip = 'C:/soun/SC3_/S1_S2/S1_S2_10.TXT';
  links(171).ip = 'C:/soun/SC3_/S2_S1/S2_S1_1.TXT';
  links(172).ip = 'C:/soun/SC3_/S2_S1/S2_S1_2.TXT';
  links(173).ip = 'C:/soun/SC3_/S2_S1/S2_S1_3.TXT';
  links(174).ip = 'C:/soun/SC3_/S2_S1/S2_S1_4.TXT';
  links(175).ip = 'C:/soun/SC3_/S2_S1/S2_S1_5.TXT';
  links(176).ip = 'C:/soun/SC3_/S2_S1/S2_S1_6.TXT';
  links(177).ip = 'C:/soun/SC3_/S2_S1/S2_S1_7.TXT';
  links(178).ip = 'C:/soun/SC3_/S2_S1/S2_S1_8.TXT';
  links(179).ip = 'C:/soun/SC3_/S2_S1/S2_S1_9.TXT';
  links(180).ip = 'C:/soun/SC3_/S2_S1/S2_S1_10.TXT';
  links(181).ip = 'C:/soun/SC3_/S3_S4/S3_S4_1.TXT';
  links(182).ip = 'C:/soun/SC3_/S3_S4/S3_S4_2.TXT';
  links(183).ip = 'C:/soun/SC3_/S3_S4/S3_S4_3.TXT';
  links(184).ip = 'C:/soun/SC3_/S3_S4/S3_S4_4.TXT';
  links(185).ip = 'C:/soun/SC3_/S3_S4/S3_S4_5.TXT';
  links(186).ip = 'C:/soun/SC3_/S3_S4/S3_S4_6.TXT';
  links(187).ip = 'C:/soun/SC3_/S3_S4/S3_S4_7.TXT';
  links(188).ip = 'C:/soun/SC3_/S3_S4/S3_S4_8.TXT';
  links(189).ip = 'C:/soun/SC3_/S3_S4/S3_S4_9.TXT';
  links(190).ip = 'C:/soun/SC3_/S3_S4/S3_S4_10.TXT';
  links(191).ip = 'C:/soun/SC3_/S4_S3/S4_S3_1.TXT';
  links(192).ip = 'C:/soun/SC3_/S4_S3/S4_S3_2.TXT';
  links(193).ip = 'C:/soun/SC3_/S4_S3/S4_S3_3.TXT';
  links(194).ip = 'C:/soun/SC3_/S4_S3/S4_S3_4.TXT';
  links(195).ip = 'C:/soun/SC3_/S4_S3/S4_S3_5.TXT';
  links(196).ip = 'C:/soun/SC3_/S4_S3/S4_S3_6.TXT';
  links(197).ip = 'C:/soun/SC3_/S4_S3/S4_S3_7.TXT';
  links(198).ip = 'C:/soun/SC3_/S4_S3/S4_S3_8.TXT';
  links(199).ip = 'C:/soun/SC3_/S4_S3/S4_S3_9.TXT';
  links(200).ip = 'C:/soun/SC3_/S4_S3/S4_S3_10.TXT';
  links(201).ip = 'C:/soun/SC3_/S5_S6/S5_S6_1.TXT';
  links(202).ip = 'C:/soun/SC3_/S5_S6/S5_S6_2.TXT';
  links(203).ip = 'C:/soun/SC3_/S5_S6/S5_S6_3.TXT';
  links(204).ip = 'C:/soun/SC3_/S5_S6/S5_S6_4.TXT';
  links(205).ip = 'C:/soun/SC3_/S5_S6/S5_S6_5.TXT';
  links(206).ip = 'C:/soun/SC3_/S5_S6/S5_S6_6.TXT';
  links(207).ip = 'C:/soun/SC3_/S5_S6/S5_S6_7.TXT';
  links(208).ip = 'C:/soun/SC3_/S5_S6/S5_S6_8.TXT';
  links(209).ip = 'C:/soun/SC3_/S5_S6/S5_S6_9.TXT';
  links(210).ip = 'C:/soun/SC3_/S5_S6/S5_S6_10.TXT';
  links(211).ip = 'C:/soun/SC3_/S6_S5/S6_S5_1.TXT';
  links(212).ip = 'C:/soun/SC3_/S6_S5/S6_S5_2.TXT';
  links(213).ip = 'C:/soun/SC3_/S6_S5/S6_S5_3.TXT';
  links(214).ip = 'C:/soun/SC3_/S6_S5/S6_S5_4.TXT';
  links(215).ip = 'C:/soun/SC3_/S6_S5/S6_S5_5.TXT';
  links(216).ip = 'C:/soun/SC3_/S6_S5/S6_S5_6.TXT';
  links(217).ip = 'C:/soun/SC3_/S6_S5/S6_S5_7.TXT';
  links(218).ip = 'C:/soun/SC3_/S6_S5/S6_S5_8.TXT';
  links(219).ip = 'C:/soun/SC3_/S6_S5/S6_S5_9.TXT';
  links(220).ip = 'C:/soun/SC3_/S6_S5/S6_S5_10.TXT';
  links(221).ip = 'C:/soun/SC3_/S7_S8/S7_S8_1.TXT';
  links(222).ip = 'C:/soun/SC3_/S7_S8/S7_S8_2.TXT';
  links(223).ip = 'C:/soun/SC3_/S7_S8/S7_S8_3.TXT';
  links(224).ip = 'C:/soun/SC3_/S7_S8/S7_S8_4.TXT';
  links(225).ip = 'C:/soun/SC3_/S7_S8/S7_S8_5.TXT';
  links(226).ip = 'C:/soun/SC3_/S7_S8/S7_S8_6.TXT';
  links(227).ip = 'C:/soun/SC3_/S7_S8/S7_S8_7.TXT';
  links(228).ip = 'C:/soun/SC3_/S7_S8/S7_S8_8.TXT';
  links(229).ip = 'C:/soun/SC3_/S7_S8/S7_S8_9.TXT';
  links(230).ip = 'C:/soun/SC3_/S7_S8/S7_S8_10.TXT';
  links(231).ip = 'C:/soun/SC3_/S8_S7/S8_S7_1.TXT';
  links(232).ip = 'C:/soun/SC3_/S8_S7/S8_S7_2.TXT';
  links(233).ip = 'C:/soun/SC3_/S8_S7/S8_S7_3.TXT';
  links(234).ip = 'C:/soun/SC3_/S8_S7/S8_S7_4.TXT';
  links(235).ip = 'C:/soun/SC3_/S8_S7/S8_S7_5.TXT';
  links(236).ip = 'C:/soun/SC3_/S8_S7/S8_S7_6.TXT';
  links(237).ip = 'C:/soun/SC3_/S8_S7/S8_S7_7.TXT';
  links(238).ip = 'C:/soun/SC3_/S8_S7/S8_S7_8.TXT';
  links(239).ip = 'C:/soun/SC3_/S8_S7/S8_S7_9.TXT';
  links(240).ip = 'C:/soun/SC3_/S8_S7/S8_S7_10.TXT'; 
  links(241).ip = 'C:/soun/SC4_/S1_S2/S1_S2_1.TXT';
  links(242).ip = 'C:/soun/SC4_/S1_S2/S1_S2_2.TXT';
  links(243).ip = 'C:/soun/SC4_/S1_S2/S1_S2_3.TXT';
  links(244).ip = 'C:/soun/SC4_/S1_S2/S1_S2_4.TXT';
  links(245).ip = 'C:/soun/SC4_/S1_S2/S1_S2_5.TXT';
  links(246).ip = 'C:/soun/SC4_/S1_S2/S1_S2_6.TXT';
  links(247).ip = 'C:/soun/SC4_/S1_S2/S1_S2_7.TXT';
  links(248).ip = 'C:/soun/SC4_/S1_S2/S1_S2_8.TXT';
  links(249).ip = 'C:/soun/SC4_/S1_S2/S1_S2_9.TXT';
  links(250).ip = 'C:/soun/SC4_/S1_S2/S1_S2_10.TXT';
  links(251).ip = 'C:/soun/SC4_/S2_S1/S2_S1_1.TXT';
  links(252).ip = 'C:/soun/SC4_/S2_S1/S2_S1_2.TXT';
  links(253).ip = 'C:/soun/SC4_/S2_S1/S2_S1_3.TXT';
  links(254).ip = 'C:/soun/SC4_/S2_S1/S2_S1_4.TXT';
  links(255).ip = 'C:/soun/SC4_/S2_S1/S2_S1_5.TXT';
  links(256).ip = 'C:/soun/SC4_/S2_S1/S2_S1_6.TXT';
  links(257).ip = 'C:/soun/SC4_/S2_S1/S2_S1_7.TXT';
  links(258).ip = 'C:/soun/SC4_/S2_S1/S2_S1_8.TXT';
  links(259).ip = 'C:/soun/SC4_/S2_S1/S2_S1_9.TXT';
  links(260).ip = 'C:/soun/SC4_/S2_S1/S2_S1_10.TXT';
  links(261).ip = 'C:/soun/SC4_/S3_S4/S3_S4_1.TXT';
  links(262).ip = 'C:/soun/SC4_/S3_S4/S3_S4_2.TXT';
  links(263).ip = 'C:/soun/SC4_/S3_S4/S3_S4_3.TXT';
  links(264).ip = 'C:/soun/SC4_/S3_S4/S3_S4_4.TXT';
  links(265).ip = 'C:/soun/SC4_/S3_S4/S3_S4_5.TXT';
  links(266).ip = 'C:/soun/SC4_/S3_S4/S3_S4_6.TXT';
  links(267).ip = 'C:/soun/SC4_/S3_S4/S3_S4_7.TXT';
  links(268).ip = 'C:/soun/SC4_/S3_S4/S3_S4_8.TXT';
  links(269).ip = 'C:/soun/SC4_/S3_S4/S3_S4_9.TXT';
  links(270).ip = 'C:/soun/SC4_/S3_S4/S3_S4_10.TXT';
  links(271).ip = 'C:/soun/SC4_/S4_S3/S4_S3_1.TXT';
  links(272).ip = 'C:/soun/SC4_/S4_S3/S4_S3_2.TXT';
  links(273).ip = 'C:/soun/SC4_/S4_S3/S4_S3_3.TXT';
  links(274).ip = 'C:/soun/SC4_/S4_S3/S4_S3_4.TXT';
  links(275).ip = 'C:/soun/SC4_/S4_S3/S4_S3_5.TXT';
  links(276).ip = 'C:/soun/SC4_/S4_S3/S4_S3_6.TXT';
  links(277).ip = 'C:/soun/SC4_/S4_S3/S4_S3_7.TXT';
  links(278).ip = 'C:/soun/SC4_/S4_S3/S4_S3_8.TXT';
  links(279).ip = 'C:/soun/SC4_/S4_S3/S4_S3_9.TXT';
  links(280).ip = 'C:/soun/SC4_/S4_S3/S4_S3_10.TXT';
  links(281).ip = 'C:/soun/SC4_/S5_S6/S5_S6_1.TXT';
  links(282).ip = 'C:/soun/SC4_/S5_S6/S5_S6_2.TXT';
  links(283).ip = 'C:/soun/SC4_/S5_S6/S5_S6_3.TXT';
  links(284).ip = 'C:/soun/SC4_/S5_S6/S5_S6_4.TXT';
  links(285).ip = 'C:/soun/SC4_/S5_S6/S5_S6_5.TXT';
  links(286).ip = 'C:/soun/SC4_/S5_S6/S5_S6_6.TXT';
  links(287).ip = 'C:/soun/SC4_/S5_S6/S5_S6_7.TXT';
  links(288).ip = 'C:/soun/SC4_/S5_S6/S5_S6_8.TXT';
  links(289).ip = 'C:/soun/SC4_/S5_S6/S5_S6_9.TXT';
  links(290).ip = 'C:/soun/SC4_/S5_S6/S5_S6_10.TXT';
  links(291).ip = 'C:/soun/SC4_/S6_S5/S6_S5_1.TXT';
  links(292).ip = 'C:/soun/SC4_/S6_S5/S6_S5_2.TXT';
  links(293).ip = 'C:/soun/SC4_/S6_S5/S6_S5_3.TXT';
  links(294).ip = 'C:/soun/SC4_/S6_S5/S6_S5_4.TXT';
  links(295).ip = 'C:/soun/SC4_/S6_S5/S6_S5_5.TXT';
  links(296).ip = 'C:/soun/SC4_/S6_S5/S6_S5_6.TXT';
  links(297).ip = 'C:/soun/SC4_/S6_S5/S6_S5_7.TXT';
  links(298).ip = 'C:/soun/SC4_/S6_S5/S6_S5_8.TXT';
  links(299).ip = 'C:/soun/SC4_/S6_S5/S6_S5_9.TXT';
  links(300).ip = 'C:/soun/SC4_/S6_S5/S6_S5_10.TXT';
  links(301).ip = 'C:/soun/SC4_/S7_S8/S7_S8_1.TXT';
  links(302).ip = 'C:/soun/SC4_/S7_S8/S7_S8_2.TXT';
  links(303).ip = 'C:/soun/SC4_/S7_S8/S7_S8_3.TXT';
  links(304).ip = 'C:/soun/SC4_/S7_S8/S7_S8_4.TXT';
  links(305).ip = 'C:/soun/SC4_/S7_S8/S7_S8_5.TXT';
  links(306).ip = 'C:/soun/SC4_/S7_S8/S7_S8_6.TXT';
  links(307).ip = 'C:/soun/SC4_/S7_S8/S7_S8_7.TXT';
  links(308).ip = 'C:/soun/SC4_/S7_S8/S7_S8_8.TXT';
  links(309).ip = 'C:/soun/SC4_/S7_S8/S7_S8_9.TXT';
  links(310).ip = 'C:/soun/SC4_/S7_S8/S7_S8_10.TXT';
  links(311).ip = 'C:/soun/SC4_/S8_S7/S8_S7_1.TXT';
  links(312).ip = 'C:/soun/SC4_/S8_S7/S8_S7_2.TXT';
  links(313).ip = 'C:/soun/SC4_/S8_S7/S8_S7_3.TXT';
  links(314).ip = 'C:/soun/SC4_/S8_S7/S8_S7_4.TXT';
  links(315).ip = 'C:/soun/SC4_/S8_S7/S8_S7_5.TXT';
  links(316).ip = 'C:/soun/SC4_/S8_S7/S8_S7_6.TXT';
  links(317).ip = 'C:/soun/SC4_/S8_S7/S8_S7_7.TXT';
  links(318).ip = 'C:/soun/SC4_/S8_S7/S8_S7_8.TXT';
  links(319).ip = 'C:/soun/SC4_/S8_S7/S8_S7_9.TXT';
  links(320).ip = 'C:/soun/SC4_/S8_S7/S8_S7_10.TXT';
  links(321).ip = 'C:/soun/SC5_/S1_S2/S1_S2_1.TXT';
  links(322).ip = 'C:/soun/SC5_/S1_S2/S1_S2_2.TXT';
  links(323).ip = 'C:/soun/SC5_/S1_S2/S1_S2_3.TXT';
  links(324).ip = 'C:/soun/SC5_/S1_S2/S1_S2_4.TXT';
  links(325).ip = 'C:/soun/SC5_/S1_S2/S1_S2_5.TXT';
  links(326).ip = 'C:/soun/SC5_/S1_S2/S1_S2_6.TXT';
  links(327).ip = 'C:/soun/SC5_/S1_S2/S1_S2_7.TXT';
  links(328).ip = 'C:/soun/SC5_/S1_S2/S1_S2_8.TXT';
  links(329).ip = 'C:/soun/SC5_/S1_S2/S1_S2_9.TXT';
  links(330).ip = 'C:/soun/SC5_/S1_S2/S1_S2_10.TXT';
  links(331).ip = 'C:/soun/SC5_/S2_S1/S2_S1_1.TXT';
  links(332).ip = 'C:/soun/SC5_/S2_S1/S2_S1_2.TXT';
  links(333).ip = 'C:/soun/SC5_/S2_S1/S2_S1_3.TXT';
  links(334).ip = 'C:/soun/SC5_/S2_S1/S2_S1_4.TXT';
  links(335).ip = 'C:/soun/SC5_/S2_S1/S2_S1_5.TXT';
  links(336).ip = 'C:/soun/SC5_/S2_S1/S2_S1_6.TXT';
  links(337).ip = 'C:/soun/SC5_/S2_S1/S2_S1_7.TXT';
  links(338).ip = 'C:/soun/SC5_/S2_S1/S2_S1_8.TXT';
  links(339).ip = 'C:/soun/SC5_/S2_S1/S2_S1_9.TXT';
  links(340).ip = 'C:/soun/SC5_/S2_S1/S2_S1_10.TXT';
  links(341).ip = 'C:/soun/SC5_/S3_S4/S3_S4_1.TXT';
  links(342).ip = 'C:/soun/SC5_/S3_S4/S3_S4_2.TXT';
  links(343).ip = 'C:/soun/SC5_/S3_S4/S3_S4_3.TXT';
  links(344).ip = 'C:/soun/SC5_/S3_S4/S3_S4_4.TXT';
  links(345).ip = 'C:/soun/SC5_/S3_S4/S3_S4_5.TXT';
  links(346).ip = 'C:/soun/SC5_/S3_S4/S3_S4_6.TXT';
  links(347).ip = 'C:/soun/SC5_/S3_S4/S3_S4_7.TXT';
  links(348).ip = 'C:/soun/SC5_/S3_S4/S3_S4_8.TXT';
  links(349).ip = 'C:/soun/SC5_/S3_S4/S3_S4_9.TXT';
  links(350).ip = 'C:/soun/SC5_/S3_S4/S3_S4_10.TXT';
  links(351).ip = 'C:/soun/SC5_/S4_S3/S4_S3_1.TXT';
  links(352).ip = 'C:/soun/SC5_/S4_S3/S4_S3_2.TXT';
  links(353).ip = 'C:/soun/SC5_/S4_S3/S4_S3_3.TXT';
  links(354).ip = 'C:/soun/SC5_/S4_S3/S4_S3_4.TXT';
  links(355).ip = 'C:/soun/SC5_/S4_S3/S4_S3_5.TXT';
  links(356).ip = 'C:/soun/SC5_/S4_S3/S4_S3_6.TXT';
  links(357).ip = 'C:/soun/SC5_/S4_S3/S4_S3_7.TXT';
  links(358).ip = 'C:/soun/SC5_/S4_S3/S4_S3_8.TXT';
  links(359).ip = 'C:/soun/SC5_/S4_S3/S4_S3_9.TXT';
  links(360).ip = 'C:/soun/SC5_/S4_S3/S4_S3_10.TXT';
  links(361).ip = 'C:/soun/SC5_/S5_S6/S5_S6_1.TXT';
  links(362).ip = 'C:/soun/SC5_/S5_S6/S5_S6_2.TXT';
  links(363).ip = 'C:/soun/SC5_/S5_S6/S5_S6_3.TXT';
  links(364).ip = 'C:/soun/SC5_/S5_S6/S5_S6_4.TXT';
  links(365).ip = 'C:/soun/SC5_/S5_S6/S5_S6_5.TXT';
  links(366).ip = 'C:/soun/SC5_/S5_S6/S5_S6_6.TXT';
  links(367).ip = 'C:/soun/SC5_/S5_S6/S5_S6_7.TXT';
  links(368).ip = 'C:/soun/SC5_/S5_S6/S5_S6_8.TXT';
  links(369).ip = 'C:/soun/SC5_/S5_S6/S5_S6_9.TXT';
  links(370).ip = 'C:/soun/SC5_/S5_S6/S5_S6_10.TXT';
  links(371).ip = 'C:/soun/SC5_/S6_S5/S6_S5_1.TXT';
  links(372).ip = 'C:/soun/SC5_/S6_S5/S6_S5_2.TXT';
  links(373).ip = 'C:/soun/SC5_/S6_S5/S6_S5_3.TXT';
  links(374).ip = 'C:/soun/SC5_/S6_S5/S6_S5_4.TXT';
  links(375).ip = 'C:/soun/SC5_/S6_S5/S6_S5_5.TXT';
  links(376).ip = 'C:/soun/SC5_/S6_S5/S6_S5_6.TXT';
  links(377).ip = 'C:/soun/SC5_/S6_S5/S6_S5_7.TXT';
  links(378).ip = 'C:/soun/SC5_/S6_S5/S6_S5_8.TXT';
  links(379).ip = 'C:/soun/SC5_/S6_S5/S6_S5_9.TXT';
  links(380).ip = 'C:/soun/SC5_/S6_S5/S6_S5_10.TXT'; 
  links(381).ip = 'C:/soun/SC5_/S7_S8/S7_S8_1.TXT';
  links(382).ip = 'C:/soun/SC5_/S7_S8/S7_S8_2.TXT';
  links(383).ip = 'C:/soun/SC5_/S7_S8/S7_S8_3.TXT';
  links(384).ip = 'C:/soun/SC5_/S7_S8/S7_S8_4.TXT';
  links(385).ip = 'C:/soun/SC5_/S7_S8/S7_S8_5.TXT';
  links(386).ip = 'C:/soun/SC5_/S7_S8/S7_S8_6.TXT';
  links(387).ip = 'C:/soun/SC5_/S7_S8/S7_S8_7.TXT';
  links(388).ip = 'C:/soun/SC5_/S7_S8/S7_S8_8.TXT';
  links(389).ip = 'C:/soun/SC5_/S7_S8/S7_S8_9.TXT';
  links(390).ip = 'C:/soun/SC5_/S7_S8/S7_S8_10.TXT';
  links(391).ip = 'C:/soun/SC5_/S8_S7/S8_S7_1.TXT';
  links(392).ip = 'C:/soun/SC5_/S8_S7/S8_S7_2.TXT';
  links(393).ip = 'C:/soun/SC5_/S8_S7/S8_S7_3.TXT';
  links(394).ip = 'C:/soun/SC5_/S8_S7/S8_S7_4.TXT';
  links(395).ip = 'C:/soun/SC5_/S8_S7/S8_S7_5.TXT';
  links(396).ip = 'C:/soun/SC5_/S8_S7/S8_S7_6.TXT';
  links(397).ip = 'C:/soun/SC5_/S8_S7/S8_S7_7.TXT';
  links(398).ip = 'C:/soun/SC5_/S8_S7/S8_S7_8.TXT';
  links(399).ip = 'C:/soun/SC5_/S8_S7/S8_S7_9.TXT';
  links(400).ip = 'C:/soun/SC5_/S8_S7/S8_S7_10.TXT';
  links(401).ip = 'C:/soun/SC6_/S1_S2/S1_S2_1.TXT';
  links(402).ip = 'C:/soun/SC6_/S1_S2/S1_S2_2.TXT';
  links(403).ip = 'C:/soun/SC6_/S1_S2/S1_S2_3.TXT';
  links(404).ip = 'C:/soun/SC6_/S1_S2/S1_S2_4.TXT';
  links(405).ip = 'C:/soun/SC6_/S1_S2/S1_S2_5.TXT';
  links(406).ip = 'C:/soun/SC6_/S1_S2/S1_S2_6.TXT';
  links(407).ip = 'C:/soun/SC6_/S1_S2/S1_S2_7.TXT';
  links(408).ip = 'C:/soun/SC6_/S1_S2/S1_S2_8.TXT';
  links(409).ip = 'C:/soun/SC6_/S1_S2/S1_S2_9.TXT';
  links(410).ip = 'C:/soun/SC6_/S1_S2/S1_S2_10.TXT';
  links(411).ip = 'C:/soun/SC6_/S2_S1/S2_S1_1.TXT';
  links(412).ip = 'C:/soun/SC6_/S2_S1/S2_S1_2.TXT';
  links(413).ip = 'C:/soun/SC6_/S2_S1/S2_S1_3.TXT';
  links(414).ip = 'C:/soun/SC6_/S2_S1/S2_S1_4.TXT';
  links(415).ip = 'C:/soun/SC6_/S2_S1/S2_S1_5.TXT';
  links(416).ip = 'C:/soun/SC6_/S2_S1/S2_S1_6.TXT';
  links(417).ip = 'C:/soun/SC6_/S2_S1/S2_S1_7.TXT';
  links(418).ip = 'C:/soun/SC6_/S2_S1/S2_S1_8.TXT';
  links(419).ip = 'C:/soun/SC6_/S2_S1/S2_S1_9.TXT';
  links(420).ip = 'C:/soun/SC6_/S2_S1/S2_S1_10.TXT';
  links(421).ip = 'C:/soun/SC6_/S3_S4/S3_S4_1.TXT';
  links(422).ip = 'C:/soun/SC6_/S3_S4/S3_S4_2.TXT';
  links(423).ip = 'C:/soun/SC6_/S3_S4/S3_S4_3.TXT';
  links(424).ip = 'C:/soun/SC6_/S3_S4/S3_S4_4.TXT';
  links(425).ip = 'C:/soun/SC6_/S3_S4/S3_S4_5.TXT';
  links(426).ip = 'C:/soun/SC6_/S3_S4/S3_S4_6.TXT';
  links(427).ip = 'C:/soun/SC6_/S3_S4/S3_S4_7.TXT';
  links(428).ip = 'C:/soun/SC6_/S3_S4/S3_S4_8.TXT';
  links(429).ip = 'C:/soun/SC6_/S3_S4/S3_S4_9.TXT';
  links(430).ip = 'C:/soun/SC6_/S3_S4/S3_S4_10.TXT';
  links(431).ip = 'C:/soun/SC6_/S4_S3/S4_S3_1.TXT';
  links(432).ip = 'C:/soun/SC6_/S4_S3/S4_S3_2.TXT';
  links(433).ip = 'C:/soun/SC6_/S4_S3/S4_S3_3.TXT';
  links(434).ip = 'C:/soun/SC6_/S4_S3/S4_S3_4.TXT';
  links(435).ip = 'C:/soun/SC6_/S4_S3/S4_S3_5.TXT';
  links(436).ip = 'C:/soun/SC6_/S4_S3/S4_S3_6.TXT';
  links(437).ip = 'C:/soun/SC6_/S4_S3/S4_S3_7.TXT';
  links(438).ip = 'C:/soun/SC6_/S4_S3/S4_S3_8.TXT';
  links(439).ip = 'C:/soun/SC6_/S4_S3/S4_S3_9.TXT';
  links(440).ip = 'C:/soun/SC6_/S4_S3/S4_S3_10.TXT';
  links(441).ip = 'C:/soun/SC6_/S5_S6/S5_S6_1.TXT';
  links(442).ip = 'C:/soun/SC6_/S5_S6/S5_S6_2.TXT';
  links(443).ip = 'C:/soun/SC6_/S5_S6/S5_S6_3.TXT';
  links(444).ip = 'C:/soun/SC6_/S5_S6/S5_S6_4.TXT';
  links(445).ip = 'C:/soun/SC6_/S5_S6/S5_S6_5.TXT';
  links(446).ip = 'C:/soun/SC6_/S5_S6/S5_S6_6.TXT';
  links(447).ip = 'C:/soun/SC6_/S5_S6/S5_S6_7.TXT';
  links(448).ip = 'C:/soun/SC6_/S5_S6/S5_S6_8.TXT';
  links(449).ip = 'C:/soun/SC6_/S5_S6/S5_S6_9.TXT';
  links(450).ip = 'C:/soun/SC6_/S5_S6/S5_S6_10.TXT';
  links(451).ip = 'C:/soun/SC6_/S6_S5/S6_S5_1.TXT';
  links(452).ip = 'C:/soun/SC6_/S6_S5/S6_S5_2.TXT';
  links(453).ip = 'C:/soun/SC6_/S6_S5/S6_S5_3.TXT';
  links(454).ip = 'C:/soun/SC6_/S6_S5/S6_S5_4.TXT';
  links(455).ip = 'C:/soun/SC6_/S6_S5/S6_S5_5.TXT';
  links(456).ip = 'C:/soun/SC6_/S6_S5/S6_S5_6.TXT';
  links(457).ip = 'C:/soun/SC6_/S6_S5/S6_S5_7.TXT';
  links(458).ip = 'C:/soun/SC6_/S6_S5/S6_S5_8.TXT';
  links(459).ip = 'C:/soun/SC6_/S6_S5/S6_S5_9.TXT';
  links(460).ip = 'C:/soun/SC6_/S6_S5/S6_S5_10.TXT';
  links(461).ip = 'C:/soun/SC6_/S7_S8/S7_S8_1.TXT';
  links(462).ip = 'C:/soun/SC6_/S7_S8/S7_S8_2.TXT';
  links(463).ip = 'C:/soun/SC6_/S7_S8/S7_S8_3.TXT';
  links(464).ip = 'C:/soun/SC6_/S7_S8/S7_S8_4.TXT';
  links(465).ip = 'C:/soun/SC6_/S7_S8/S7_S8_5.TXT';
  links(466).ip = 'C:/soun/SC6_/S7_S8/S7_S8_6.TXT';
  links(467).ip = 'C:/soun/SC6_/S7_S8/S7_S8_7.TXT';
  links(468).ip = 'C:/soun/SC6_/S7_S8/S7_S8_8.TXT';
  links(469).ip = 'C:/soun/SC6_/S7_S8/S7_S8_9.TXT';
  links(470).ip = 'C:/soun/SC6_/S7_S8/S7_S8_10.TXT';
  links(471).ip = 'C:/soun/SC6_/S8_S7/S8_S7_1.TXT';
  links(472).ip = 'C:/soun/SC6_/S8_S7/S8_S7_2.TXT';
  links(473).ip = 'C:/soun/SC6_/S8_S7/S8_S7_3.TXT';
  links(474).ip = 'C:/soun/SC6_/S8_S7/S8_S7_4.TXT';
  links(475).ip = 'C:/soun/SC6_/S8_S7/S8_S7_5.TXT';
  links(476).ip = 'C:/soun/SC6_/S8_S7/S8_S7_6.TXT';
  links(477).ip = 'C:/soun/SC6_/S8_S7/S8_S7_7.TXT';
  links(478).ip = 'C:/soun/SC6_/S8_S7/S8_S7_8.TXT';
  links(479).ip = 'C:/soun/SC6_/S8_S7/S8_S7_9.TXT';
  links(480).ip = 'C:/soun/SC6_/S8_S7/S8_S7_10.TXT';
  links(481).ip = 'C:/soun/SC7_/S1_S2/S1_S2_1.TXT';
  links(482).ip = 'C:/soun/SC7_/S1_S2/S1_S2_2.TXT';
  links(483).ip = 'C:/soun/SC7_/S1_S2/S1_S2_3.TXT';
  links(484).ip = 'C:/soun/SC7_/S1_S2/S1_S2_4.TXT';
  links(485).ip = 'C:/soun/SC7_/S1_S2/S1_S2_5.TXT';
  links(486).ip = 'C:/soun/SC7_/S1_S2/S1_S2_6.TXT';
  links(487).ip = 'C:/soun/SC7_/S1_S2/S1_S2_7.TXT';
  links(488).ip = 'C:/soun/SC7_/S1_S2/S1_S2_8.TXT';
  links(489).ip = 'C:/soun/SC7_/S1_S2/S1_S2_9.TXT';
  links(490).ip = 'C:/soun/SC7_/S1_S2/S1_S2_10.TXT';
  links(491).ip = 'C:/soun/SC7_/S2_S1/S2_S1_1.TXT';
  links(492).ip = 'C:/soun/SC7_/S2_S1/S2_S1_2.TXT';
  links(493).ip = 'C:/soun/SC7_/S2_S1/S2_S1_3.TXT';
  links(494).ip = 'C:/soun/SC7_/S2_S1/S2_S1_4.TXT';
  links(495).ip = 'C:/soun/SC7_/S2_S1/S2_S1_5.TXT';
  links(496).ip = 'C:/soun/SC7_/S2_S1/S2_S1_6.TXT';
  links(497).ip = 'C:/soun/SC7_/S2_S1/S2_S1_7.TXT';
  links(498).ip = 'C:/soun/SC7_/S2_S1/S2_S1_8.TXT';
  links(499).ip = 'C:/soun/SC7_/S2_S1/S2_S1_9.TXT';
  links(500).ip = 'C:/soun/SC7_/S2_S1/S2_S1_10.TXT';
  links(501).ip = 'C:/soun/SC7_/S3_S4/S3_S4_1.TXT';
  links(502).ip = 'C:/soun/SC7_/S3_S4/S3_S4_2.TXT';
  links(503).ip = 'C:/soun/SC7_/S3_S4/S3_S4_3.TXT';
  links(504).ip = 'C:/soun/SC7_/S3_S4/S3_S4_4.TXT';
  links(505).ip = 'C:/soun/SC7_/S3_S4/S3_S4_5.TXT';
  links(506).ip = 'C:/soun/SC7_/S3_S4/S3_S4_6.TXT';
  links(507).ip = 'C:/soun/SC7_/S3_S4/S3_S4_7.TXT';
  links(508).ip = 'C:/soun/SC7_/S3_S4/S3_S4_8.TXT';
  links(509).ip = 'C:/soun/SC7_/S3_S4/S3_S4_9.TXT';
  links(510).ip = 'C:/soun/SC7_/S3_S4/S3_S4_10.TXT'; 
  links(511).ip = 'C:/soun/SC7_/S4_S3/S4_S3_1.TXT';
  links(512).ip = 'C:/soun/SC7_/S4_S3/S4_S3_2.TXT';
  links(513).ip = 'C:/soun/SC7_/S4_S3/S4_S3_3.TXT';
  links(514).ip = 'C:/soun/SC7_/S4_S3/S4_S3_4.TXT';
  links(515).ip = 'C:/soun/SC7_/S4_S3/S4_S3_5.TXT';
  links(516).ip = 'C:/soun/SC7_/S4_S3/S4_S3_6.TXT';
  links(517).ip = 'C:/soun/SC7_/S4_S3/S4_S3_7.TXT';
  links(518).ip = 'C:/soun/SC7_/S4_S3/S4_S3_8.TXT';
  links(519).ip = 'C:/soun/SC7_/S4_S3/S4_S3_9.TXT';
  links(520).ip = 'C:/soun/SC7_/S4_S3/S4_S3_10.TXT'; 
  links(521).ip = 'C:/soun/SC7_/S5_S6/S5_S6_1.TXT';
  links(522).ip = 'C:/soun/SC7_/S5_S6/S5_S6_2.TXT';
  links(523).ip = 'C:/soun/SC7_/S5_S6/S5_S6_3.TXT';
  links(524).ip = 'C:/soun/SC7_/S5_S6/S5_S6_4.TXT';
  links(525).ip = 'C:/soun/SC7_/S5_S6/S5_S6_5.TXT';
  links(526).ip = 'C:/soun/SC7_/S5_S6/S5_S6_6.TXT';
  links(527).ip = 'C:/soun/SC7_/S5_S6/S5_S6_7.TXT';
  links(528).ip = 'C:/soun/SC7_/S5_S6/S5_S6_8.TXT';
  links(529).ip = 'C:/soun/SC7_/S5_S6/S5_S6_9.TXT';
  links(530).ip = 'C:/soun/SC7_/S5_S6/S5_S6_10.TXT';  
  links(531).ip = 'C:/soun/SC7_/S6_S5/S6_S5_1.TXT';
  links(532).ip = 'C:/soun/SC7_/S6_S5/S6_S5_2.TXT';
  links(533).ip = 'C:/soun/SC7_/S6_S5/S6_S5_3.TXT';
  links(534).ip = 'C:/soun/SC7_/S6_S5/S6_S5_4.TXT';
  links(535).ip = 'C:/soun/SC7_/S6_S5/S6_S5_5.TXT';
  links(536).ip = 'C:/soun/SC7_/S6_S5/S6_S5_6.TXT';
  links(537).ip = 'C:/soun/SC7_/S6_S5/S6_S5_7.TXT';
  links(538).ip = 'C:/soun/SC7_/S6_S5/S6_S5_8.TXT';
  links(539).ip = 'C:/soun/SC7_/S6_S5/S6_S5_9.TXT';
  links(540).ip = 'C:/soun/SC7_/S6_S5/S6_S5_10.TXT';  
  links(541).ip = 'C:/soun/SC7_/S7_S8/S7_S8_1.TXT';
  links(542).ip = 'C:/soun/SC7_/S7_S8/S7_S8_2.TXT';
  links(543).ip = 'C:/soun/SC7_/S7_S8/S7_S8_3.TXT';
  links(544).ip = 'C:/soun/SC7_/S7_S8/S7_S8_4.TXT';
  links(545).ip = 'C:/soun/SC7_/S7_S8/S7_S8_5.TXT';
  links(546).ip = 'C:/soun/SC7_/S7_S8/S7_S8_6.TXT';
  links(547).ip = 'C:/soun/SC7_/S7_S8/S7_S8_7.TXT';
  links(548).ip = 'C:/soun/SC7_/S7_S8/S7_S8_8.TXT';
  links(549).ip = 'C:/soun/SC7_/S7_S8/S7_S8_9.TXT';
  links(550).ip = 'C:/soun/SC7_/S7_S8/S7_S8_10.TXT';
  links(551).ip = 'C:/soun/SC7_/S8_S7/S8_S7_1.TXT';
  links(552).ip = 'C:/soun/SC7_/S8_S7/S8_S7_2.TXT';
  links(553).ip = 'C:/soun/SC7_/S8_S7/S8_S7_3.TXT';
  links(554).ip = 'C:/soun/SC7_/S8_S7/S8_S7_4.TXT';
  links(555).ip = 'C:/soun/SC7_/S8_S7/S8_S7_5.TXT';
  links(556).ip = 'C:/soun/SC7_/S8_S7/S8_S7_6.TXT';
  links(557).ip = 'C:/soun/SC7_/S8_S7/S8_S7_7.TXT';
  links(558).ip = 'C:/soun/SC7_/S8_S7/S8_S7_8.TXT';
  links(559).ip = 'C:/soun/SC7_/S8_S7/S8_S7_9.TXT';
  links(560).ip = 'C:/soun/SC7_/S8_S7/S8_S7_10.TXT'; 
  
  %% calculating files
  
  for i=1:560
      display(sprintf('Calculating file [%d]',i));
      file_read(links(i).ip);
  end
  
  
  