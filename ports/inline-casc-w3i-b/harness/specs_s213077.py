"""specs_s213077.py - batch 213077: typed table entries to a 5-argument slot call, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g504c90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    M = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)
    this = obj(c, 0x20, {0x60: sl(5)}, nslots=0x30)
    T = rnd(c, 0x80)
    eng = rnd(c, 0x100)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)
    ents = {}
    for k in range(5):
        p = rnd(c, 8)
        f = r.choice([0.0, 1.0, -2.5, 100.0, float('nan'), float('inf'), r.uniform(-9, 9)])
        e.wbytes(p, struct.pack('<f', f) if k else struct.pack('<I', r.choice([0, 0x10, r.getrandbits(32)])))
        t = r.choice([0, 2, 0, 2, 0, 2, 1, 3, 0xff, r.getrandbits(8)]) if r.random() < 0.5 else r.choice([0, 2])
        e.wbytes(p + 4, bytes([t]))
        ents[k] = p
    tab_a = rnd(c, 0x10)
    tab_b = rnd(c, 0x10)
    rec = rnd(c, 0x10)
    e.w32(rec + 4, tab_a)
    e.w32(rec + 8, tab_b)
    pe = rnd(c, 8)

    def g5003d0(emu, k):
        tabp = emu.reg('ecx')
        idx = emu.arg32(0)
        return pe if tabp == tab_b else ents.get(idx, 0)
    hook_rec(c, 0x5003d0, 1, this=True, ret=g5003d0)
    hook_rec(c, 0x5002f0, 1, this=True)
    return [this, rec]


S(0x504c90, 'table_args_slot_call', 'thiscall', None, ret='eax', gen=g504c90)
