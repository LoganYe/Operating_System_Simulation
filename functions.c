pReg->SP = USER_STACK_ADDR;
sys_SP = SYS_STACK_ADDR;

while((pReg->IR = mem[pReg->PC++]) != END)
{
	PC_protection(pReg->PC, sys_mode);

	switch(pReg->IR)
	{
	case LOAD_VALUE;
	    pReg->AC = mem[pReg->PC++];
	    break;
	case LOAD_ADDR;
	    Addr = mem[pReg->PC++];
	    mem_protection(Addr, sys_mode);
        pReg->AC = mem[Addr];
   		break;
    case LOADIND_ADDR;
        Addr = mem[pReg->PC++];
        mem_protection(Addr, sys_mode);
        pReg->AC = mem[mem[Addr]];
        break;
    case LOADIDXX_ADDR;
    	Addr = mem[pReg->PC++];
    	mem_protection(Addr, sys_mode);
    	pReg->AC = mem[Addr + (pReg->X)];
    	break;
    case LOADIDXY_ADDR;
    	Addr = mem[pReg->PC++];
    	mem_protection(Addr, sys_mode);
    	pReg->AC = mem[Addr + (pReg->Y)];
    	break;
    case LOADSPX;
    	pReg->AC = mem[(pReg->SP)+(pReg->X)];
    	break;
    case STORE_ADDR;
    	Addr = mem[pReg->PC++];
    	mem_protection(Addr, sys_mode);
    	mem(Addr) = pReg->AC;
    	break;
    case GET;
    	pReg->AC = get_random();
    	break;
    case PUT_PORT;
    	Port = mem[pReg->PC++];
    	if(Port == 1)
    		printf(%d, pReg->AC);
    	else if(Port == 2)
    		printf(*c, pReg->AC);
    	break;
    case ADDX;
        pReg->AC += pReg->X;
        break;
    case ADDY;
        pReg->AC += pReg->Y;
        break;
    case SUBX;
        pReg->AC -= pReg->X;
        break;
    case SUBY;
        pReg->AC -= pReg->Y;
        break;
    case COPYTOX;
        pReg->X = pReg->AC;
        break;
    case COPYFROMX;
        pReg->AC = pReg->X;
        break;
    case COPYTOY;
        pReg->Y = pReg->AC;
        break;
    case COPYFROMY;
        pReg->AC = pReg->Y;
        break;
    case COPYTOSP;
        pReg->SP = pReg->AC;
        break;
    case COPYFROMSP;
        pReg->AC = pReg->SP;
        break;
    case JUMP_ADDR;
        Addr = mem[pReg->PC++];
        
	}
}
