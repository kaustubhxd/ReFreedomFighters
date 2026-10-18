"""specs_s213120.py - batch 213120: text list row formatter through a sprintf-like virtual call, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

STACK_LO = 0x0ff00000 - 0x00100000
STACK_TOP = 0x0ff00000


def g5fc030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def norm(v):
        return 0x57ac0000 if STACK_LO <= v < STACK_TOP else v

    def cstr(emu, addr, n=0x20):
        b = bytes(emu.rbytes(addr, n))
        return b.split(b'\0')[0]

    def h14(emu, rr):
        short = emu.arg32(2) == 0x6b93a4
        n = 6 if short else 9
        vals = [norm(emu.arg32(i)) for i in range(n)]
        buf = emu.arg32(1)
        txt = bytes(r.choice(b'abcdefghijklmnopqrstuvwxyz 0123456789.%') for _ in range(r.choice([0, 1, 3, 8, 12])))
        emu.wbytes(buf, txt + b'\0')
        row = ('fmt14', norm(emu.reg('ecx'))) + tuple(vals)
        if not short:
            lab = emu.arg32(6)
            if STACK_LO <= lab < STACK_TOP:
                row += (cstr(emu, lab),)
        emu.calllog.append(row)
        emu.ret(eax=r.getrandbits(32), argbytes=0)
    P = obj(c, 0x40, {0x14: e.stub_fn('fmt14', h14), 0x1c: pystub(c, 1, this=True, ret=lambda emu, k: r.getrandbits(32))}, nslots=0x20)
    e.w32(0x724270, P)
    # the text buffer starts with leftover bytes
    e.wbytes(0x724280, bytes(r.getrandbits(8) for _ in range(0x40)))
    n = r.choice([0, 1, 2, 3, 4])
    this = rnd(c, 0x40)
    e.w32(this + 0x20, n)
    items = []
    for _ in range(n):
        it = obj(c, 0xc10, {0x24: pystub(c, 0, this=True, ret=lambda emu, k: r.getrandbits(32)),
                            0x28: pystub(c, 0, this=True, ret=lambda emu, k: r.getrandbits(32))}, nslots=0x20)
        kind = r.choice([2, 2, 4, 4, 0, 1, 3, 5, 15, r.randrange(16)])
        e.wbytes(it + 0xac, bytes([(r.getrandbits(8) & 0xf0) | kind]))
        e.w32(it + 0x16, r.choice([0, 0x677b5a, 0x6b9334, r.getrandbits(32)]))
        e.wbytes(it + 0xa, struct.pack('<f', f32(r.choice([0.0, 1.0, 2.5, -1.0, r.uniform(-5, 5)]))))
        e.w32(it + 0x20, r.choice([0, 0, 1, r.getrandbits(32)]))
        e.w32(it + 0x24, r.getrandbits(32))
        e.w32(it + 0xac2, r.getrandbits(32))
        items.append(it)
    arr = e.alloc(4 * 6, 4)
    for i, it in enumerate(items):
        e.w32(arr + 4 * i, it)
    e.w32(this + 0x18, arr)
    Q = obj(c, 0x20, {0x4: pystub(c, 0, this=True, st0=lambda emu, k: f32(r.choice([0.0, 1.0, 2.5, -1.0, r.uniform(-5, 5)])))}, nslots=0x10)
    e.w32(this + 0x24, Q)
    outp = e.alloc(4, 4)
    e.w32(outp, r.getrandbits(32))
    a = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 0xffffffff, 0xfffffffe])
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, a, outp]


S(0x5fc030, 'list_row_text', 'thiscall', None, ret='eax', gen=g5fc030)
