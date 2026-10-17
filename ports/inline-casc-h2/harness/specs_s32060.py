from pilot import S
from recruits_util import obj

def gen_62cf00(c):
    # stdcall(arg0, arg1) ret 0 - complex conditional dispatcher
    # Branches on arg1: 0xf, 0x19, other
    # May write to [arg0] and [arg0+8]

    arg0_obj = c.rng.choice([
        None,  # NULL pointer path
        c.emu.alloc(0x100, 4),  # Valid object
    ])

    arg1 = c.rng.choice([
        0xf,
        0x19,
        0x1c,
        c.rng.getrandbits(16),
    ])

    if arg0_obj is not None:
        # Set up [arg0+0xc] - used in condition
        val_at_c = c.rng.choice([0, 1, c.rng.getrandbits(32)])
        c.emu.w32(arg0_obj + 0xc, val_at_c)

        # Set up [arg0+8] for potential increment
        c.emu.w32(arg0_obj + 8, c.rng.getrandbits(32))

    return [arg0_obj if arg0_obj else 0, arg1]

S(0x62cf00, 'sub_62cf00', 'cdecl', 2, ret='eax', gen=gen_62cf00)
