from pilot import S
from recruits_util import obj

def gen_563d40(c):
    # cdecl(arg0, arg1, arg2) ret 12: conditional reset after increment
    # Increments [arg1], compares with arg2, conditionally resets [arg1] to arg0

    # Create output buffer for arg1 to write to
    output = obj(c, 0x20, {})

    # Generate random initial value for [arg1]
    initial_val = c.rng.getrandbits(16)
    c.emu.w32(output, initial_val)

    # Generate random arg0 (reset value)
    arg0 = c.rng.getrandbits(32)

    # Generate random arg2 (threshold) with reasonable range
    arg2 = c.rng.getrandbits(16) + 1

    return [arg0, output, arg2]

S(0x563d40, 'sub_563d40', 'stdcall', 3, ret=None, gen=gen_563d40)
