"""specs_s240023.py - Sonnet-w4a: CRT x87/SSE helpers."""
import struct
import pe_emu
from unicorn.x86_const import UC_X86_REG_FPCW
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _g633aad(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # _except1(8 dwords of the argument block) returns an x87 value that the helper discards
    hook_rec(c, 0x634e6c, 8, pop=0, st0=lambda em, k: 0.5,
             side=lambda em, k: em.calllog.append(('fpcw_in_except1', em.mu.reg_read(UC_X86_REG_FPCW))))
    for i in range(0x20):
        e.wbytes(0x6c166f + i, bytes([r.choice([0, 0, 0x80, 0x01, 0x40, 0xff, r.getrandbits(8)])]))
    return [r.choice([1, 2, 4, 8, 0x10, 0x20, 0x04, 0x18, 3, 7, 9, r.randrange(0, 0x20)]), _w(c)]


S(0x633aad, 'GUESS raise fp exception', ('regs', ['edx', 'xmm0']), None, ret=None, gen=_g633aad, note='batch240023')


def _fp80(d):
    """a Python float as the (mantissa, sign+exponent) pair unicorn takes for an x87 register"""
    b = struct.unpack('<Q', struct.pack('<d', d))[0]
    sign = b >> 63
    ex = (b >> 52) & 0x7ff
    fr = b & ((1 << 52) - 1)
    if ex == 0 and fr == 0:
        return 0, sign << 15
    if ex == 0x7ff:
        return (1 << 63) | (fr << 11), (sign << 15) | 0x7fff
    if ex == 0:         # denormal double: normalise
        sh = 52 - fr.bit_length() + 1
        return (fr << (11 + sh)) & ((1 << 64) - 1), (sign << 15) | (16383 - 1022 - sh)
    return (1 << 63) | (fr << 11), (sign << 15) | (ex - 1023 + 16383)


def _g634670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.random()
    if k < 0.3:
        d = r.choice([2.0 ** 62, -2.0 ** 62, 2.0 ** 62, 2.0 ** 32, -2.0 ** 32, 0.0, -0.0, 0.5, -0.5, 1.0, -1.0, 1.5, -1.5, 2.5, -2.5, 0.9999999, -0.9999999, 2.0 ** 31, -2.0 ** 31, 2.0 ** 63, -2.0 ** 63,
                      2.0 ** 62, 4e18, -4e18, 1e300, -1e300, 1e-300, float('inf'), float('-inf'), float('nan'), 5e-324, 2.0 ** 52 + 0.5])
    elif k < 0.5:
        d = r.uniform(-100, 100)
    elif k < 0.8:
        d = r.choice([-1, 1]) * 2.0 ** r.randrange(-5, 70) * r.uniform(1, 2)
    else:
        d = float(r.randrange(-2 ** 40, 2 ** 40)) + r.choice([0, 0.5, 0.25, 0.75])
    e.w32(0x72580c, r.choice([0, 0, 1, 2, 3]))
    mant, exp = _fp80(d)

    state = {'done': False}

    def entry(em, res):          # first arrival: run `fld qword [SCRATCH+0x40]; jmp <entry>` so that st0 holds the input; second arrival: go on
        if state['done']:
            return
        state['done'] = True
        eip = em.reg('eip') if 'eip' in pe_emu.REGS else em.mu.reg_read(pe_emu.UC_X86_REG_EIP)
        em.wbytes(pe_emu.SCRATCH + 0x40, struct.pack('<d', d))
        code = b'\xdd\x05' + struct.pack('<I', pe_emu.SCRATCH + 0x40) + b'\xe9' + b'\0\0\0\0'
        t = em._alloc_stub_code(code)
        em.mu.mem_write(t + 7, struct.pack('<i', eip - (t + 11)))
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, t)
    for a in (0x634670, e.decomp[0x634670]):
        e.hook(a, entry)
        recruits_util._HOOKED.add(a)
    return []


import recruits_util
S(0x634670, 'GUESS _ftol2_sse', 'cdecl', None, ret='eax:edx', gen=_g634670, note='batch240023')
