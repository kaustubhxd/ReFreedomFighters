from pilot import S

def gen_533ba0(c):
    # cdecl() - calls verified function 0x5390b0 and returns 1
    # No parameters
    return []

S(0x533ba0, 'sub_533ba0', 'cdecl', 0, ret='al', gen=gen_533ba0)
