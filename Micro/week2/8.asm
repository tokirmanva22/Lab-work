LDA 5000H
MOV B,A
LDA 5001H
ANA B
STA 5003H

LDA 5000H
MOV B,A
LDA 5001H
ORA B
STA 5004H

LDA 5000H
MOV B,A
LDA 5001H
ANA B
XRA 5005H

LDA 5000H
MOV B,A
LDA 5001H
CMP B
STA 5006H

LDA 5000H
CMA
STA 5007H

LDA 5000H
RLC
STA 5008H

LDA 5000H
RRC
STA 5009H

LDA 5000H
RAL
STA 500AH


LDA 5000H
RAR
STA 500BH

hlt 
