	.include "single_inverter.inc"

NET_DEBUG	.set	0	; do not change this

IB1 		.set	0	; Open loop INVERTER drive to excite power stage
IB4 		.set	1	; 全部功能
		
			.def	_control_run_init
			.def	_control_run


ZeroNet		.usect "Net_terminals",8,1,1
DummyNet	.usect "Net_terminals",7,1,1

			.text

_control_run_init:

			.if(IB1)
				;HRFULLBDG_BIPOLAR_DRV_INIT
				;ADC2CONT_DRV_INIT
			.endif ; IB1

			.if(IB4)
				ADC2CONT_DRV_INIT
				;HRFULLBDG_BIPOLAR_DRV_INIT
			.endif ; IB4
				LRETR

_control_run:	CONTEXT_SAVE				;call macro	

;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;                       IB1
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			.if(IB1)
				.ref	_duty			
				MOVL 	XAR3,#CMPA1		
				MOVL 	XAR4,#CMPA2
				; Outputs for EPWM1A and EPWM2A (Hi Res)		
				SETC    SXM,OVM
				MOVW	DP,		#_duty
				MOV		ACC,	@_duty+0
				MOV  	*XAR3,	ACC 				; CMP1A:CMPAHR1(31:8) = ACC
            	MOV		ACC,	@_duty+1
            	MOV  	*XAR4,	ACC              ; CMP2A:CMPAHR2(31:8) = ACC
				
				;SINGEN_1CH	
				.ref	_sindata
				.ref	_sin_length
				.ref	_Vref
				.ref	_N
				MOVW	DP, 	#_sin_length
				MOVL	XAR0,	#_sin_length	;查表值
				MOVL	XAR1,	#_N
				MOVL	XAR2,	#_Vref			;出口地址
				MOVL    XAR3,	#(_sindata+0)		;XAR3->SINTAB_360
	;IB2
				MOV		ACC,	*XAR0
				ADD     ACC,	#1	
				MOV		*XAR0,	ACC
				SUB		ACC,	@_N	
				BF		LOOP1,	LT
				MOV		*XAR0,	#0

LOOP1:  		MOVL	XAR1,	@_sin_length
				MOV     ACC,	*+XAR3[AR1]		;取表        
				MOVL	*XAR2,	ACC				;输出
				
				.ref	_period
				.ref	_period1
				.ref	_period2
				; Outputs for EPWM1A and EPWM2A (Hi Res)		
				MOVW    DP, #_period
				MOV 	T,*XAR2
				MPY 	ACC,T,@_period       	; ACC = Duty*TBPRD*m  (Q15) , max<=(TBPRD-2*Tdead)/TBPRD to invoid dead time making D lost
           		ADD     ACC,@_period2<<15     	; ACC = Duty*TBPRD + TBPRD  (Q15)
				MOVW	DP,		#_duty
				MOV  	@_duty+0,	AH 				; CMP1A:CMPAHR1(31:8) = ACC
            	
            	MOVW    DP, #_period1
            	MOV 	T,*XAR2
				MPY		ACC,T,@_period1
				MOVW    DP, #_period			; ACC = -1*Duty*TBPRD*m  (Q15) , max<=(TBPRD-2*Tdead)/TBPRD to invoid dead time making D lost
            	ADD		ACC,@_period2<<15
				MOVW	DP,		#_duty
            	MOV  	@_duty+1,	AH              ; CMP2A:CMPAHR2(31:8) = ACC
            
			.endif ; IB1

;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;@@@@@                 IB4					@@@@@@
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			.if(IB4)
;=======================================================
;输出PWM			
				.ref	_duty
						
				MOVL 	XAR3,#CMPA1		
				MOVL 	XAR4,#CMPA2
				; Outputs for EPWM1A and EPWM2A (Hi Res)		
				SETC    SXM,OVM
				MOVW	DP,		#_duty
				MOV		ACC,	@_duty+0
				MOV  	*XAR3,	ACC 				; CMP1A:CMPAHR1(31:8) = ACC
            	MOV		ACC,	@_duty+1
            	MOV  	*XAR4,	ACC					; CMP2A:CMPAHR2(31:8) = ACC
;IB4
;=======================================================
;读取ADC采样输出								
				ADC2CONT_DRV					;ADC采样

;IB4
;=======================================================
;save voc, iLc, iRc, voc_delay, iRc_delay

				.ref	_AdcResults
				.ref	_ADC
				.ref	_ADML 
				.ref 	_AdcOffset
				.ref	_OLRG
				MOVW	DP, #_AdcOffset
				MOVL 	XAR0, #_AdcOffset		;Q28 format, Unipolar input
   	        	MOVW	DP, #_AdcResults
   	        	MOV		AL, #0
				MOV		AH, @_AdcResults+0		;Q28
				SUBL	ACC, *XAR0				;减去直流电流偏置
				MOVW	DP, #_ADC
				MOVL	@_ADC+0, ACC			;Q28	voc

				MOVL	XT, ACC	
   	        	
   	        	MOVW	DP, #_AdcResults
   	        	MOV		AL, #0 	
				MOV		AH, @_AdcResults+1		;Q28
				SUBL	ACC, *XAR0				;减去直流电流偏置						
				MOVW	DP,	#_ADC
				MOVL	@_ADC+2, ACC			;Q28	iLc
				
				MOVW	DP, #_AdcResults
   	        	MOV		AL, #0 	
				MOV		AH, @_AdcResults+2		;Q28
				MOVW	DP,	#_ADC
				MOVL	@_ADC+4, ACC			;Q28	iRc	
				MOVL	ACC, *XAR0				;减去直流电流偏置
				MOVW	DP,	#_ADC
				SUBL	ACC, @_ADC+4
				MOVL	@_ADC+4, ACC			;Q28	iRc
				
				QMPYL	P, XT, @_ADC+4			;Q28*Q28=Q56-->Q24
				MOVL	ACC, @P
				MOVW	DP,	#_ADML
				MOVL	@_ADML+0, ACC			;Q24	vo*iR
;IB4
;-------------------------------------------------------
;overload protection				
				MOVW	DP,	#_ADML
				MOVL	ACC, @_ADML+0			;Q24	vo*iR
				MOVW	DP,	#_OLRG
				MOVL	ACC, @_OLRG				;Q24
				ADDCL	ACC, @P					;Q24
				MOVL	@_OLRG, ACC				;Q24

				.ref	_sin_length
				.ref	_NNN
				MOVW	DP, #_sin_length
				MOV		ACC, @_sin_length
				SUB		ACC,	#0		
				BF		exitol,	NEQ
				
				MOVW	DP,	#_OLRG
				MOVL	XT, @_OLRG				;Q24
				MOV		AH, #0
				MOV		AL, #0
				MOVL	@_OLRG, ACC
				MOVW	DP,	#_NNN				;Q25
				QMPYL	ACC, XT, @_NNN			;Q24*Q25=Q49-->Q17

				.ref	_POWER
				MOVW	DP, #_POWER
				SUBL	ACC, @_POWER			;Q17
				BF		exitol,	LT
;protect###############################
				EALLOW 
				MOVL	XAR1, #TZFRC1
				MOV		*XAR1, #0x6	
				INTR	INT2	
				EDIS				
;protect###############################																
exitol:

;IB4
;-------------------------------------------------------
;vo, iR 100 delay

				.ref	_vodata
				.ref	_iRdata
				.ref	_vo_length

				MOVW	DP, 	#_vo_length
				MOVL	XAR0,	#_vo_length			;查表值
				MOVW	DP, 	#_AdcOffset
				MOVL 	XAR2, 	#_AdcOffset			;Q28 format, Unipolar input
				MOVW	DP, 	#_vodata
				MOVL    XAR3,	#(_vodata+0)		;XAR3->SINTAB_360
				MOVW	DP, 	#_iRdata
				MOVL    XAR4,	#(_iRdata+0)		;XAR4->SINTAB_360

				MOV		ACC,	*XAR0
				ADD     ACC,	#1	
				MOV		*XAR0,	ACC
				SUB		ACC,	#100	
				BF		LOOPQ,	LT
				MOV		*XAR0,	#0

LOOPQ:  		
				MOVW	DP, 	#_vo_length
				MOVL	XAR1,	@_vo_length
		;		MOVW	DP, 	#_vodata	
				MOV     AH,	*+XAR3[AR1]				;取表        
   	        	MOV		AL, #0 	
				SUBL	ACC, *XAR2					;减去直流电流偏置
				MOVW	DP,	#_ADC
				MOVL	@_ADC+6, ACC				;Q28 vo_delay

   	        	MOVW	DP, #_AdcResults
				MOV		ACC, @_AdcResults+0			;Q12
		;		MOVW	DP, 	#_vodata
				MOV		*+XAR3[AR1], ACC			;save voc

		;		MOVW	DP, 	#_iRdata
				MOV     AH,	*+XAR4[AR1]				;取表
   	        	MOV		AL, #0 
				MOVW	DP,	#_ADC
				MOVL	@_ADC+8, ACC			;Q28	iRc	
				MOVL	ACC, *XAR2				;减去直流电流偏置
				MOVW	DP,	#_ADC
				SUBL	ACC, @_ADC+8
				MOVL	@_ADC+8, ACC			;Q28	iRc

   	        	MOVW	DP, #_AdcResults
				MOV		ACC, @_AdcResults+2			;Q12
		;		MOVW	DP, 	#_iRdata
				MOV		*+XAR4[AR1], ACC			;save iRc

;IB4
;-------------------------------------------------------
;
				
				.ref	_pq
				MOVW	DP,	#_ADML
				MOVL	ACC, @_ADML+0			;Q24	vo*iR 
				MOVW	DP,	#_ADC				
				MOVL	XT, @_ADC+6				;Q28	vo_delay
				QMPYL	P, XT, @_ADC+8			;Q28*Q28=Q56-->Q24
												;vo_delay*iR_delay
				ADDCL   ACC,    @P				;Q24
				ASR64	ACC:P, #1				;Q24
				MOVW	DP,	#_pq				
				MOVL	@_pq+0, ACC				;Q24

				MOVW	DP,	#_ADC				
				MOVL	XT, @_ADC+0				;Q28	vo
				QMPYL	P, XT, @_ADC+8			;Q28*Q28=Q56-->Q24
												;vo*iR_delay
				MOVL	ACC, @P
				MOVL	XT, @_ADC+4				;Q28	iR
				QMPYL	P, XT, @_ADC+6			;Q28*Q28=Q56-->Q24
				
												;iR*vo_delay	

				ADDL   ACC,    @P				;Q24
				ASR64	ACC:P, #1				;Q24
				MOVW	DP,	#_pq				
				MOVL	@_pq+2, ACC				;Q24

;IB4
;=======================================================
;PQ caculation 

;@@@@@			P  LPF
;Uo(n)=1.58*wc*Ts*Ui(n)+Uo(n-1)/(1+wc*Ts)
;	  =tl1*Ui(n)+tl*Uo(n-1)
				.ref	_terg
				.ref	_tlp
				.ref	_tlp1
				.ref	_tlq
				.ref	_tlq1

				MOVW	DP,	#_pq
				MOVL	XT, @_pq+0		;Q24
				MOVW	DP,	#_tlp1			;Q29
				QMPYL	P,	XT,	@_tlp1		;Ui(n)*tl1 Q24*Q29=Q53-->Q21
				MOVL	ACC, @P				;Q21

				MOVW	DP,	#_terg
				MOVL	XT,	@_terg+0		;load U(n-1) Q28
				MOVW	DP,	#_tlp			;Q25
				QMPYL	P,	XT,	@_tlp		;E(n)*ks Q28*Q25=Q53-->Q21
				ADDCL   ACC,    @P			;Q21

				.ref	_LPFulimit
				.ref	_LPFllimit
				MOVW	DP, 	#_LPFulimit	;
				MOVL	XAR6,	#_LPFulimit	;Q21	
				MOVL	XAR7,	#_LPFllimit	;Q21
				MINL	ACC, *XAR6				
				MAXL	ACC, *XAR7  
				
				LSL		ACC, #7				;Q21+7-->Q28

				MOVW	DP,	#_terg
				MOVL	@_terg+0,   ACC		;Q28
				
;IB4
				MOVW	DP,	#_ADC
				MOVL	XT, @_ADC+6				;vo_delay
				QMPYL	P,	XT,	@_ADC+4			;vo_dealy*iR Q28*Q28=Q56-->Q24
				MOVL	ACC, @P
				MOVW	DP,	#_ADML
				MOVL	@_ADML+2, ACC

;IB4
;@@@@@			Q  LPF
;Uo(n)=1.58*wc*Ts*Ui(n)+Uo(n-1)/(1+wc*Ts)
;	  =tl1*Ui(n)+tl*Uo(n-1)
				
				MOVW	DP,	#_pq
				MOVL	XT, @_pq+2		;Q24
				MOVW	DP,	#_tlq1			;Q29
				QMPYL	P,	XT,	@_tlq1		;Ui(n)*tl1 Q24*Q29=Q53-->Q21
				MOVL	ACC, @P				;Q21

				MOVW	DP,	#_terg
				MOVL	XT,	@_terg+2		;load U(n-1) Q28
				MOVW	DP,	#_tlq			;Q25
				QMPYL	P,	XT,	@_tlq		;E(n)*ks Q28*Q25=Q53-->Q21
				ADDCL   ACC,    @P			;Q21

				.ref	_LPFulimit
				.ref	_LPFllimit
				MOVW	DP, 	#_LPFulimit	;
				MOVL	XAR6,	#_LPFulimit	;Q21	
				MOVL	XAR7,	#_LPFllimit	;Q21
				MINL	ACC, *XAR6				
				MAXL	ACC, *XAR7  
				
				LSL		ACC, #7				;Q21+7-->Q28

				MOVW	DP,	#_terg
				MOVL	@_terg+2,   ACC		;Q28
;IB4
;=======================================================
;caculate the feedback of voltage and current
exit:		
				.ref	_kcv
				.ref	_kci
				.ref	_FDrg
				MOVW	DP,	#_kcv				;Q19
				MOVL	XT, @_kcv
				MOVW	DP, #_ADC
				QMPYL	ACC, XT, @_ADC+0		;Q19+Q28=Q47-->Q15，vo*kcv
				MOVW	DP, #_FDrg
				ADDL	ACC,	@_FDrg+0
				ASR64	ACC:P,	#1				
				MOVL	@_FDrg+0, ACC			;Q15
;IB4
				MOVW	DP,	#_kci				;Q19
				MOVL	XT, @_kci
				MOVW	DP, #_ADC
				QMPYL	ACC, XT, @_ADC+2		;Q26+Q28=Q54-->Q22，iL*kci
				MOVW	DP, #_FDrg
				MOVL	@_FDrg+2, ACC			;Q22

;IB4
;=======================================================
;调用正弦表 
				;SINGEN_1CH	
				.ref	_sindata
				.ref	_Vref
				.ref	_N
				MOVW	DP, 	#_sin_length
				MOVL	XAR0,	#_sin_length	;查表值
				MOVL	XAR1,	#_N
				MOVL	XAR2,	#_Vref			;出口地址
				MOVL    XAR3,	#(_sindata+0)		;XAR3->SINTAB_360
;IB4
				MOV		ACC,	*XAR0
				ADD     ACC,	#1	
				MOV		*XAR0,	ACC
				SUB		ACC,	*XAR1	
				BF		LOOP1,	LT
				MOV		*XAR0,	#0

LOOP1:  		MOVL	XAR1,	@_sin_length
				MOV     ACC,	*+XAR3[AR1]		;取表        
				MOVL	*XAR2,	ACC				;输出

;IB4
;=======================================================
;DQ method
;V=Vr-nq*Q
				.ref	_mpp
				.ref	_nqq
				.ref	_Wref
				.ref	_W
				.ref	_NUM
				.ref	_Pw
				.ref	_V
				.ref	_Vr
				MOVW	DP,	#_terg
				MOVL	XT,	@_terg+2			;Q28
		;///////////////////////////		
		;		MOV		AH, #0x0099
		;		MOV		AL, #0x1AA2
		;		MOVL	XT, ACC
		;///////////////////////////
				
				MOVW	DP,	#_V
				MOVL	ACC, @_V				;Q16
				MOVW	DP, #_nqq				;Q20
				QMPYL	P, XT, @_nqq			;Q28+Q20=Q48-->Q16
				SUBL	ACC, @P					;Q16
				MOVW	DP,	#_Vr
				MOVL	@_Vr, ACC				;Q16
				
				MOVW	DP,	#_Vref
				MOV		AL, #0
				MOV		AH, @_Vref				;Q31

				MOVL	XT, ACC				
				MOVW	DP,	#_Vr				;Q16
				QMPYL	P, XT, @_Vr				;Q16+Q31=Q47-->Q15
				MOVL	ACC, @P
				MOVW	DP,	#_Vref
				MOVL	@_Vref, ACC

;-------------------------------------------------------
;w=wr-mp*P
				MOVW	DP,	#_terg
				MOVL	XT,	@_terg+0			;Q28
				
		;///////////////////////////		
		;		MOV		AH, #0x0099
		;		MOV		AL, #0x1AA2
		;		MOVL	XT, ACC
		;///////////////////////////

				MOVW	DP,	#_Wref				
				MOVL	ACC, @_Wref				;Q14
				MOVW	DP, #_mpp				;Q18
				QMPYL	P, XT, @_mpp			;Q28+Q18=Q46-->Q14
				SUBL	ACC, @P					;Q14
				
				MOVW	DP,	#_W
				MOVL	@_W, ACC				;Q14
;division		
				MOVB	ACC, #0
				MOVW	DP,	#_NUM				;Q14
				MOVL	P, @_NUM				
				MOVW	DP,	#_W
				RPT		#31
			||SUBCUL	ACC, @_W				;Q14
				MOVW	DP,	#_Pw	
				MOVL	@_Pw, P					;Q14-Q14=Q0
				MOVL	ACC,@_Pw					

				MOVL 	XAR2, #TBPRD1
				MOVL 	XAR3, #TBPRD2
				MOVL 	XAR4, #TBPRD6
				MOV		*XAR2, ACC
				MOV		*XAR3, ACC
				MOV		*XAR4, ACC
				
				.ref	_period
				.ref	_period1
				MOVW	DP, #_period
				MOV		@_period, ACC
				MOV		AH, #0
				MOV		AL, #0
				SUB		ACC, @_period
				MOVW	DP, #_period1
				MOV		@_period1, ACC	

;IB4
;=======================================================
;电压PI环 
;V(n)=V(n-1)+(Kp+Ki)*e(n)-Kp*e(n-1)  TI=1/KI
				MOVW	DP,  #_Vref
				MOVL	ACC, @_Vref      ;Q15
				MOVW    DP,  #_FDrg
				ADDL	ACC, @_FDrg+0		;E(N)Q15

				.ref	_Eupperlimit
				.ref	_Elowerlimit
				MOVW	DP, 	#_Eupperlimit	;
				MOVL	XAR6,	#_Eupperlimit	;Q15	
				MOVL	XAR7,	#_Elowerlimit	;Q15
				MINL	ACC, *XAR6				
				MAXL	ACC, *XAR7  

				MOV		T,	ACC
				MPY		ACC,T,#0x2000			;Q15+13=Q28
;IB4
				.ref	_temp
				.ref	_kp
				.ref	_kp1
				.ref	_ks
				
				SETC    SXM,OVM
				MOVW	DP,  #_temp
				MOVL	@_temp+2,	ACC			;save E(n) Q28
				MOVL	ACC,	@_temp+4		;Vo(n-1)	Q22
				MOVL	XT,		@_temp+2		;load E(n) Q28
				MOVW	DP,  #_ks
				QMPYL	P,	XT,	@_ks			;E(n)*ks Q28*Q26=Q54-->Q22			
				ADDCL   ACC,    @P				;ACC=ACC+P+carry

				MOVL	XT,		@_temp+0		;E(n-1)		Q28
				MOVW	DP,  #_kp1
				QMPYL	P,	XT,	@_kp1			;E(n-1)*Kp	Q28*Q26=Q54-->Q22				
				ADDCL   ACC,    @P				;Q22 E(n)*ks+Vo(n-1)-E(n-1)*kp				;ADDL	ACC,P<<PM				
;IB4				
				.ref	_upperlimit
				.ref	_lowerlimit
				MOVW	DP, 	#_upperlimit	;
				MOVL	XAR6,	#_upperlimit	;Q22	
				MOVL	XAR7,	#_lowerlimit	;Q22
				MINL	ACC, *XAR6				
				MAXL	ACC, *XAR7

				.ref	_Iref
				MOVW	DP,  #_Iref
				MOVL	XAR1,	#_Iref			;Q22
				MOVW	DP,  #_temp
				MOVL	@_temp+4, ACC			;SAVE next Vo(n-1) Q22
				MOVL	*XAR1, ACC				;Q22 Iref=Vo(n)
				MOVL	ACC,	@_temp+2		;Q28 load E(n)
				MOVL	@_temp+0,	ACC			;Q28 save E(n-1)
;IB4
;=======================================================
;电流环					
				.ref	_kpi
				MOVW	DP,	#_FDrg				;
				MOVL	ACC,	*XAR1			;Q22
				ADDL	ACC,	@_FDrg+2		;Q22  	
				MOVL	XT,	ACC					;Q22
				MOVW	DP,	#_kpi				;kpi,q25
				QMPYL	ACC,XT,@_kpi			;Q25+22=Q47->Q15
				
				.ref	_iupperlimit
				.ref	_ilowerlimit
				MOVW	DP, 	#_iupperlimit	;
				MOVL	XAR6,	#_iupperlimit	;Q15	
				MOVL	XAR7,	#_ilowerlimit	;Q15
				MINL	ACC, *XAR6				
				MAXL	ACC, *XAR7
				MOVL	*XAR1, ACC	
;IB4
;=======================================================
;软启动
				.ref	_M

				MOVW	DP, 	#_sin_length
				MOVL	XAR0,	#_sin_length	;查表值
				MOVL	XAR1,	#_Iref
				MOVL	XAR2,	#_M
				MOVL	XAR3,	#GPASET
									
;if M=128,then jump to loop3
				MOV		ACC,	*XAR2
				SUB		ACC,	#128		
				BF		loop3,	EQ
;if M>128,then jump to loop4
				MOV		ACC,	*XAR2
				SUB		ACC,	#129
				BF		loop4,	EQ
				;M<128:
;if sin_length=0,then M++,else jump to loop2
				MOV		ACC,	*XAR0
				SUB		ACC,	#0		
				BF		loop2,	NEQ
				;M++				
				MOV		ACC,	*XAR2
				ADD     ACC,	#1					
				MOV		*XAR2,	ACC
;PI output=Vo,let Vo=(Vo*M)/128
loop2:			
;=======================================================
				MOV 	T,	*XAR1				;Q15
				MPY 	ACC,	T,	@_M			;Q15*Q0-->Q15
           		ASR64   ACC:P,	#7				;1/128,Q15	
				MOVL	*XAR1, ACC				;Q15
;-------------------------------------------------------
				.ref	_CFLAG
				.ref	_i
				MOVW	DP,		#_sin_length				
				MOVL	XAR4,	#GPADAT
				ADDB	XAR4,	#1
				MOVL	XAR5,	#_sin_length

				MOV		ACC,	*XAR4				;读取I/O口的电平
				AND		ACC,	#0x0200				;屏蔽其他I/O口
				MOVW	DP,	#_i
				MOV		@_i,	ACC					;save output of SYNC
;if SYNC=0,then jump to loopc
				SUB		ACC,	#0
				BF		loopc,	EQ					
;SYNC=1
				XOR		ACC,	@_CFLAG				;ACC=SYNC XOR CFLAG
;if ACC!=0,then jump to SETCN,else exit. 
				SUB		ACC,	#0					
				BF		SETCN,	NEQ
				LB		exit1
;IB4
;SYNC=0
loopc:						
				MOVW	DP,	#_i
				MOV		ACC,	@_i
				MOVW	DP,	#_CFLAG
				XOR		ACC,	@_CFLAG				;ACC=SYNC XOR CFLAG	
;if ACC!=0,then jump to SETCC,else exit.
				SUB		ACC,	#0
				BF		SETCC,	NEQ
				LB		exit1				
;STCN:reset N,let N=0x0014 and set CFLAG.
SETCN:
				MOV		*XAR5,	#0x0397			;20 is delay time
				MOVW	DP,	#_CFLAG
				MOV		@_CFLAG,#0x0200
				LB		exit1					;exit	
;SETCC:reset CFLAG,let CFLAG=0;
SETCC:			
				MOVW	DP,	#_CFLAG
				MOV		@_CFLAG,#0x0000	
				LB		exit1					;exit
				
exit1:	
;-------------------------------------------------------
				LB		loop4
;=======================================================
loop3:
				ADDB	XAR3,	#1
				MOVW	*XAR3,	#0x00000020

				MOV		ACC,	*XAR2
				ADD     ACC,	#1					
				MOV		*XAR2,	ACC
				
				.ref	_mp
				.ref	_nq
				MOVW	DP, #_mp				;Q18
				MOVL	ACC, @_mp
				MOVW	DP, #_mpp				;Q18
				MOVL	@_mpp, ACC				
				
				MOVW	DP, #_nq				;Q20
				MOVL	ACC, @_nq
				MOVW	DP, #_nqq				;Q20
				MOVL	@_nqq, ACC	
								
loop4:

;IB4
;=======================================================
;计算PWM涑觯４嬖赿uty0,duty1

				; Outputs for EPWM1A and EPWM2A (Hi Res)		
				MOVW    DP, #_period
				MOVL	XAR1,	#_Iref
				MOV 	T,*XAR1
				MPY 	ACC,T,@_period       	; ACC = Duty*TBPRD*m  (Q15) , max<=(TBPRD-2*Tdead)/TBPRD to invoid dead time making D lost
           		ADD     ACC,@_period<<15     	; ACC = Duty*TBPRD + TBPRD  (Q15)
				MOVW	DP,		#_duty
				MOV  	@_duty+0,	AH 				; CMP1A:CMPAHR1(31:8) = ACC
            	
            	MOVW    DP, #_period1
            	MOV 	T,*XAR1
				MPY		ACC,T,@_period1
				MOVW    DP, #_period			; ACC = -1*Duty*TBPRD*m  (Q15) , max<=(TBPRD-2*Tdead)/TBPRD to invoid dead time making D lost
            	ADD		ACC,@_period<<15
				MOVW	DP,		#_duty
            	MOV  	@_duty+1,	AH              ; CMP2A:CMPAHR2(31:8) = ACC
;IB4            	
			.endif ; IB4


;===================================
EXIT_ISR
;===================================
; Interrupt management before exit

			MOVW 	DP,#ETCLR1>>6
			MOV 	@ETCLR1,#0x01			; Clear EPWM1 Int flag

			MOVW 	DP,#PIEACK>>6			; Acknowledge PIE interrupt Group 3
			MOV 	@PIEACK,#PIEACK_GROUP3

			MOVW 	DP,#ADCST>>6
			MOV 	@ADCST,#0x010			; Clear INT SEQ1 Int flag

			MOVW 	DP,#PIEACK>>6			; Acknowledge PIE interrupt Group 1
			MOV 	@PIEACK,#PIEACK_GROUP1
; Restore context & return
			CONTEXT_REST
			IRET		

;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;@@@@@@@				the	END			  @@@@@@@
;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@		