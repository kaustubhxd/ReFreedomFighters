"""specs_s349.py - residue-15, batch 349: 0x46d070 (thiscall, one argument). The exe helpers (0x46cee0, 0x4e11e0, 0x4e12f0, 0x4e12e0, 0x4e14a0,
0x4e0fd0, 0x4e1600, 0x4e1b30) are hooked by address: each records its ECX and arguments; 0x4e1600 returns a per-run byte (0..4).
The object and the argument are random blocks; the float at +0xc0 is nonzero."""
import struct
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    ret1600 = rng.choice([0, 1, 3, 4])
    names = {0x46cee0: 'h46cee0', 0x4e11e0: 'h4e11e0', 0x4e12f0: 'h4e12f0', 0x4e12e0: 'h4e12e0', 0x4e14a0: 'h4e14a0',
             0x4e0fd0: 'h4e0fd0', 0x4e1600: 'h4e1600', 0x4e1b30: 'h4e1b30'}

    def mk(addr, name):
        def h(em, r):
            n = {0x46cee0: 1, 0x4e11e0: 2, 0x4e12f0: 2, 0x4e12e0: 2, 0x4e14a0: 2, 0x4e0fd0: 1, 0x4e1600: 0, 0x4e1b30: 0}[addr]
            args = tuple(em.arg32(k) for k in range(n))
            em.calllog.append((name, addr, em.reg('ecx'), args))
            if addr == 0x4e1600:
                em.ret(eax=ret1600, argbytes=0)
            else:
                em.ret(eax=0, argbytes=4 * n)
        return h

    for a, nm in names.items():
        e.hook(a, mk(a, nm))
    this = e.alloc(0x100, 4)
    e.wbytes(this, rng.randbytes(0x100))
    e.w32(this + 0xc0, struct.unpack('<I', struct.pack('<f', rng.uniform(0.5, 50.0)))[0])
    e.w32(this + 0xa8, struct.unpack('<I', struct.pack('<f', rng.uniform(-10.0, 10.0)))[0])
    e.w32(this + 0xb0, struct.unpack('<I', struct.pack('<f', rng.uniform(-10.0, 10.0)))[0])
    e.w32(this + 0xb4, struct.unpack('<I', struct.pack('<f', rng.uniform(-10.0, 10.0)))[0])
    obj = e.alloc(0x40, 4)
    e.wbytes(obj, rng.randbytes(0x40))
    return [this, obj]


S(0x46d070, 'serialize46d070 (GUESS)', 'thiscall', None, ret=None, gen=_gen, note='batch349; ret 4; helpers hooked by address')
