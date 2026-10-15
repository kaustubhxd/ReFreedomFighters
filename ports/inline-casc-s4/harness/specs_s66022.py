"""specs_s66022.py - cascade s4 batch 66022: 0x63f2d0 (get or create the record bound to an owner)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g63f2d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    sysobj(c)
    so = int.from_bytes(bytes(e.rbytes(0x70039c, 4)), 'little')
    e.w32(so + 0x3c, r.getrandbits(32))

    def mkrec():
        rec = e.alloc(0x60, 8)
        e.wbytes(rec, bytes(r.getrandbits(8) for _ in range(0x60)))
        e.wbytes(rec + 5, bytes([r.choice([0, 1, 2, 3, 0x80])]))
        e.wbytes(rec + 6, r.choice([0xffff, 0, 3, 7, 0xffff]).to_bytes(2, 'little'))
        e.wbytes(rec + 0x42, bytes([r.choice([0, 1, 2, 3])]))
        return rec
    arr = e.alloc(4 * 0x1000, 8)
    recs = [mkrec() for _ in range(3)]
    for k in range(0x1000):
        e.w32(arr + 4 * k, recs[k % 3])
    t = obj(c, 0x300, {0x8c: pystub(c, 1, this=True), 0x88: pystub(c, 1, this=True)})
    newrec = mkrec()
    e.w32(t + 0x68, arr)
    mgr = obj(c, 0x20, {8: pystub(c, 0, this=True, ret=newrec)})
    e.w32(t + 0x21c, mgr)
    hook_rec(c, 0x4ce7b0, 0, this=True, ret=r.choice([0, 5, 0x20, 0xfff, 0x1fff, 0xffe]))
    own = e.alloc(0x80, 8)
    idx = r.choice([0, 0, 1, 2, 0x3, 0x1005, 0x2001, 0x10, 0x801, 0x1802])
    e.wbytes(own + 0x5a, idx.to_bytes(2, 'little'))
    a = e.alloc(0x20, 8)
    e.w32(a + 8, own)
    return [t, a]


S(0x63f2d0, 'GUESS get or create the record bound to an owner', 'thiscall', None, ret='eax', gen=_g63f2d0, note='batch66022')
