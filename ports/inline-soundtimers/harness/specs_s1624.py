"""specs_s1624.py - soundtimers batch 1624: ZDllSound::SetGroupVolume.
The sound-object list at +0x53b2 is a Python iterator: vtable +0x4c writes the first reference to *out, +0x5c writes
the next one and returns the current one. SRefToPtr (database +0x60) maps references to objects written by the spec."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, sysobj, clear_hooks
from specs_s1617 import _mgr  # noqa: F401 (keeps the import graph of the pool specs)


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _pow_stub(c):
    """CRT pow (SSE2 convention: base in xmm0, exponent in xmm1, double result in xmm0). Python's pow for these
    inputs is exact enough: the original is only reached with base 10 and exponent (v-100)/20."""
    from pe_emu import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    def h(e, rr):
        def d(reg):
            return struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(reg) & (2 ** 64 - 1)))[0]
        x, y = d(UC_X86_REG_XMM0), d(UC_X86_REG_XMM1)
        try:
            z = x ** y
        except OverflowError:
            z = float('inf')
        except ZeroDivisionError:
            z = float('inf')
        e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', float(z)))[0])
        e.ret()
    c.emu.stub_import('_libm_sse2_pow_precise', h)


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    _pow_stub(c)
    refs = [r.getrandbits(32) | 1 for _ in range(r.randint(0, 5))]
    objs = {}
    for ref in refs:
        o = rnd(c, 0x100)
        c.emu.w32(o + 0x2c, r.choice([0, 1, 2, 3]))
        c.emu.w32(o + 4, r.choice([3, 5, 2]))
        objs[ref] = o
    st = {'i': 0}

    def sref(e, rr):
        ref = e.r32(e.reg('esp') + 4)
        e.ret(eax=objs.get(ref, 0), argbytes=4)
    dbslot = c.emu.stub_fn('SRefToPtr', sref)

    def it4c(e, rr):
        out = e.r32(e.reg('esp') + 4)
        st['i'] = 0
        e.w32(out, refs[0] if refs else 0)
        e.ret(eax=0, argbytes=4)

    def it5c(e, rr):
        out = e.r32(e.reg('esp') + 4)
        cur = refs[st['i']] if st['i'] < len(refs) else 0
        st['i'] += 1
        nxt = refs[st['i']] if st['i'] < len(refs) else 0
        e.w32(out, nxt)
        e.ret(eax=cur, argbytes=4)
    lst = obj(c, 0x40, {0x4c: c.emu.stub_fn('it4c', it4c), 0x5c: c.emu.stub_fn('it5c', it5c)})
    db = obj(c, 0x80, {0x60: dbslot})
    sysobj(c, db=db)
    d = rnd(c, 0x5300)
    c.emu.w32(d + 0x53b2, c.emu.r32(lst))  # the list object is embedded at +0x53b2: its vtable pointer sits there
    c.emu.w8(d + 0x50a9, r.choice([0, 0, 1]))
    group = r.randint(0, 4)   # in-range groups only: a wild index writes outside the table (faults in both builds)
    for g in range(4):
        c.emu.w8(d + g * 9 + 0x515d, r.choice([0, 0, 1]))
    k = r.random()
    value = r.choice([0, 1, 50, 100, 99, 37, -5, 120, 1000, r.randint(0, 100), r.getrandbits(32)])
    mode = r.choice([0, 1, 2, 2, 3, r.getrandbits(32)])
    return [d, group, value, mode]


S(0x5398f0, 'ZDllSound::SetGroupVolume', 'thiscall', None, ret=None, gen=_gen, note='batch1624; mode-2 curve, group scale')
