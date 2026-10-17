"""specs_s993.py - area 56 claim A59 (0x633910, CRT float-to-unsigned helper used by round()).

Float-to-unsigned conversion: takes u32 float bit pattern as fastcall argument, returns u32 in eax.
Handles normal values in [0, 2^32), NaN, and out-of-range values. Out-of-range calls error handler 0x633aad.
ret='eax'."""
import struct
from pilot import S


def _rnd_f32(rng, lo, hi):
    """Generate a random float in [lo, hi)."""
    return lo + rng.uniform(0.0, 1.0) * (hi - lo)


def _gen(c):
    e = c.emu
    rng = c.rng

    error_count = [0]

    def h_633aad(e2, r):
        # Error handler stub: called on NaN, negative, or >= 2^32
        error_count[0] += 1
        e2.calllog.append(('H633aad', error_count[0]))
        # Return 0x80000000 for out-of-range
        e2.ret(eax=0x80000000, argbytes=4)
    e.hook(0x633aad, h_633aad)

    # Generate test floats covering:
    # - Normal positive values in [0, 2^32)
    # - Edge cases near 0 and 2^32
    # - Negative values
    # - Special values (NaN, Inf)

    # Weighted distribution: most cases are normal values, some edge cases and errors
    kind = rng.randrange(100)
    if kind < 50:
        # Normal positive value
        f = _rnd_f32(rng, 0.0, 4000000000.0)
    elif kind < 75:
        # Edge cases
        cases = [0.0, 0.5, 0.999999, 1.0, 4294967295.0, 4294967296.0, 4294967297.0,
                 float('inf'), float('-inf')]
        f = cases[rng.randrange(len(cases))]
    elif kind < 95:
        # Negative values
        f = -_rnd_f32(rng, 0.1, 1000000.0)
    else:
        # NaN
        f = float('nan')

    # Convert float to u32 bit pattern for FASTCALL argument (ecx)
    f_bits = struct.unpack('<I', struct.pack('<f', f))[0]
    return [f_bits]


S(0x633910, 'CRT float-to-unsigned (round helper)', 'fastcall', None,
  ret='eax', gen=_gen, note='unclaimed-56 A59; 0x633aad is GUESS error stub')
