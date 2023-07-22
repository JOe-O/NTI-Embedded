#define SET_BIT(REG,BitNo) (REG |= (1<<BitNo))

#define CLR_BIT(REG,BitNo) (REG &= ~(1<<BitNo))

#define TGL_BIT(REG,BitNo) (REG ^= (1<<BitNo))

#define GET_BIT(REG,BitNo) ((REG >> BitNo) & 1)
