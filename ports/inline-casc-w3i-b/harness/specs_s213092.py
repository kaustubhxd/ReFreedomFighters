"""specs_s213092.py - batch 213092: object serializer with list and record tables, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g4640f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def w10(emu, rr):
        p, n = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('w10', n, bytes(emu.rbytes(p, n)), p))
        emu.ret(eax=r.getrandbits(32), argbytes=8)
    Sx = obj(c, 0x20, {0x10: e.stub_fn('w10', w10), 0x60: sl(1), 0x24: sl(1), 0x3c: sl(1), 0x4c: sl(1)}, nslots=0x40)
    this = rnd(c, 0x140)
    nitems = r.choice([0, 1, 2, 3, 4])
    items = [rnd(c, 0x20) for _ in range(nitems)]
    state = {'i': 0}

    def l4c(emu, rr):
        state['i'] = 0
        emu.calllog.append(('l4c',))
        emu.ret(eax=r.getrandbits(32), argbytes=4)

    def l64(emu, rr):
        i = state['i']
        state['i'] += 1
        it = items[i] if i < len(items) else 0
        emu.calllog.append(('l64', it))
        emu.ret(eax=it, argbytes=4)
    Lobj = obj(c, 0x20, {0x14: sl(0, nitems), 0x4c: e.stub_fn('l4c', l4c), 0x64: e.stub_fn('l64', l64)}, nslots=0x40)
    e.w32(this + 0x18, 0 if r.random() < 0.15 else Lobj)
    Hobj = obj(c, 0x20, {0x4: sl(1)}, nslots=0x10)
    e.w32(this + 0x6c, Hobj)
    nrec = r.choice([0, 1, 2, 3])
    recs = rnd(c, 0x18 * 4)
    for i in range(nrec):
        pick = r.random()
        if pick < 0.2 or not items:
            v = 0
        elif pick < 0.7:
            v = r.choice(items) + 4
        else:
            v = r.choice(items) + 8
        e.w32(recs + 0x18 * i + 0x14, v)
    e.w32(this + 0x1c, recs)
    e.w32(this + 0x20, nrec)
    e.w32(this + 0x58, r.getrandbits(32))
    e.wbytes(this + 0x116, struct.pack('<f', r.uniform(-9, 9)))
    hook_rec(c, 0x45f960, 1, this=True, ret=lambda emu, k: r.choice([0, 1, 1, 1, 0x100, 0xff, r.getrandbits(32)]))
    hook_rec(c, 0x463ff0, 1, this=True)
    return [this, Sx]


S(0x4640f0, 'serialize_list_object', 'thiscall', None, ret='al', gen=g4640f0)
