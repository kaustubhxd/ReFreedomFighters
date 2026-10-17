"""specs_s240018.py - Sonnet-w4a: float->int64 helpers and the CRT cpu probe."""
import struct
import pe_emu
from pilot import S
from recruits_util import clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _f32bits(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _gen_f(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = r.random()
    if k < 0.45:
        bits = r.choice([0x59800000, 0xd9800000, 0x59ffffff, 0x597fffff, 0x5a000000, 0xda000000, 0x5a7fffff, 0x5a5fffff, 0x7f7ffff0, 0x5f000000, 0xdf000000, 0x00000003, 0x80000003, 0, 0x80000000, 0x7f800000, 0xff800000, 0x7fc00000, 0xffc00000, 0x00000001, 0x007fffff, 0x7f7fffff, 0x5f000000,
                         0xdf000000, 0x5effffff, 0xdf000001, 0x3f800000, 0xbf800000, _w(c)])
    elif k < 0.5:
        bits = _f32bits(r.uniform(-1e5, 1e5))
    elif k < 0.8:
        bits = _f32bits(r.choice([-1, 1]) * 2.0 ** r.randrange(-30, 70) * r.uniform(1, 2))
    else:
        bits = _w(c)

    def fperr(em, res):      # 0x633aad: edx = error code, xmm0 = operand; logged, then returns
        em.calllog.append(('fperr', em.reg('edx'), em.reg('xmm0') & 0xffffffffffffffff))
        em.ret()
    c.emu.hook(0x633aad, fperr)
    import recruits_util
    recruits_util._HOOKED.add(0x633aad)
    return [bits]


def _install_cpuid(e):
    from unicorn import UC_HOOK_INSN
    from unicorn.x86_const import UC_X86_INS_CPUID, UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDX
    if getattr(e, '_w4a_cpuid', None) is not None:
        return
    e._w4a_cpuid = {}

    def cb(uc, _):
        leaf = uc.reg_read(UC_X86_REG_EAX)
        v = e._w4a_cpuid.get(leaf, (0, 0, 0, 0))
        for reg, val in zip((UC_X86_REG_EAX, UC_X86_REG_EBX, UC_X86_REG_ECX, UC_X86_REG_EDX), v):
            uc.reg_write(reg, val)
        return True
    e.mu.hook_add(UC_HOOK_INSN, cb, None, 1, 0, UC_X86_INS_CPUID)


def _gen_cpu(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _install_cpuid(e)
    intel = r.random() < 0.7
    vend = (0x756e6547, 0x6c65746e, 0x49656e69) if intel else (0x68747541, 0x444d4163, 0x69746e65)
    if intel and r.random() < 0.2:
        vend = (vend[0] ^ (1 << r.randrange(32)), vend[1], vend[2])
    sig = r.choice([0x106c0, 0x20660, 0x20670, 0x30650, 0x30660, 0x30670, 0x106c1, 0x00f0ff0 | 0x30650, 0x506e3, _w(c)])
    feat = _w(c) & 0xfffffffc
    if r.random() < 0.7:
        feat |= r.choice([0x100000, 0x100000 | 0x8000000 | 0x10000000, 0x100000 | 0x8000000, 0x100000 | 0x10000000])
    ebx7 = r.choice([0, 0x20, 0x200, 0x220, _w(c)])
    e._w4a_cpuid.clear()
    e._w4a_cpuid[0] = (r.choice([0, 1, 6, 7, 8, 13]), vend[0], vend[1], vend[2])
    e._w4a_cpuid[1] = (sig, _w(c), feat, _w(c))
    e._w4a_cpuid[7] = (0, ebx7, _w(c), _w(c))
    for g in (0x72580c, 0x6f5680, 0x725810):
        e.w32(g, _w(c))
    hook_rec(c, 0x663bc2, 1, pop=4, ret=lambda em, k: r.choice([0, 1, 1, 1]))
    return []


S(0x63392e, 'GUESS float to int64 (mode 3)', ('regs', ['xmm0']), None, ret='eax:edx', gen=_gen_f, note='batch240018')
S(0x633910, 'GUESS float to int64 (mode 1)', ('regs', ['xmm0']), None, ret='eax:edx', gen=_gen_f, note='batch240018')
S(0x634b1b, 'GUESS cpu feature probe', 'cdecl', None, ret='eax', gen=_gen_cpu, note='batch240018')
