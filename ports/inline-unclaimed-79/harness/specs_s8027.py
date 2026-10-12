"""specs_s8027.py - unclaimed core row 0x481800 (docs/20-unclaimed-79.md). Each function gets its own random object.
The vtable callees are stubbed and logged; the sub-object slot 0x114 pops 24 (branch 2) or 20 (branch 1) bytes, chosen per run."""
from pilot import S
import os, sys
for _d in ("..", "../.."):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, "shared-harness")
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

def _obj(c, size):
    a = c.emu.alloc(size, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(size)))
    return a

def _g(c):
    branch2 = c.rng.random() < 0.5
    arg = c.rng.getrandbits(32)
    self_ = _obj(c, 0x800)
    flags = c.rng.getrandbits(32)
    if branch2:
        flags |= 0x1800
    else:
        flags &= ~0x1800 & 0xffffffff
    c.emu.w32(self_ + 0x417, flags)
    c.emu.w32(self_ + 0x413, c.rng.getrandbits(32))
    r514 = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    def log(tag, n):
        def h(e, r):
            e.calllog.append((tag, e.reg("ecx"), tuple(e.arg32(k) for k in range(n))))
        return h
    def ret(argb, eax):
        def h(e, r):
            e.ret(eax=eax() if callable(eax) else eax, argbytes=argb)
        return h
    def mk(tag, n, argb, eax_fn):
        lg = log(tag, n)
        def h(e, r):
            lg(e, r)
            e.ret(eax=eax_fn(), argbytes=argb)
        return h
    rnd = lambda: c.rng.getrandbits(32)
    b_obj = _obj(c, 0x40)
    bvt = c.emu.fake_vtable("VtB81", 0x180, {0x128: mk("b slot 128", 1, 4, rnd)})
    c.emu.w32(b_obj, bvt)
    b_ret = b_obj if (branch2 and c.rng.random() < 0.7) else 0
    sub = _obj(c, 0x40)
    subvt = c.emu.fake_vtable("VtSub81", 0x180, {
        0x58: mk("sub slot 58", 1, 4, lambda: b_ret),
        0x114: mk("sub slot 114", 6 if branch2 else 5, 24 if branch2 else 20, rnd),
        0x4c: mk("sub slot 4c", 1, 4, rnd),
    })
    c.emu.w32(sub, subvt)
    sysobj = _obj(c, 0xa4)
    c.emu.w32(sysobj + 0x9b, sub)
    c.emu.w32(0x70039c, sysobj)
    selfvt = c.emu.fake_vtable("VtSelf81", 0x180, {
        0x514: mk("self slot 514", 0, 0, lambda: r514),
        0x130: mk("self slot 130", 2, 8, lambda: 0),
        0x598: mk("self slot 598", 1, 4, lambda: 0),
    })
    c.emu.w32(self_, selfvt)
    return [self_, arg]

S(0x481800, '(GUESS) 0x481800 two-branch sub-object update', 'thiscall', None, ret=None, gen=_g,
  note='unclaimed core row (parked, resumed): sub-object at [0x70039c]+0x9b and this vtable, callees stubbed')
