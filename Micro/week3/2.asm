;ascii to decimal
LDA 5000H
CPI 0AH
JnC JUMP
SBI 07h
JUMP: SBI 30h
STA 5001H
HLT
