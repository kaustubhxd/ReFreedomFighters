"""specs_s38064.py - cascade s8 batch 38064: 0x428fe0. thiscall(stream) ret 4. this is a 0xc0 random block; stream slot 0xc (custom stub: records, stores the child object or 0 into the out pointer,
returns a signed code), child slots 0x2c/0x34/0xc/0x10 return codes (negative sometimes), this+0x81/0x85 random (so the clamps >2 / >0x10 fire both ways), 0x436060 and 0x428960 hooked (0x428960
returns 0 or random nonzero), logger and assert hooks always set, sysobj at 0x70039c with +0x9db dword."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g428fe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    so = sysobj(c)
    e.wbytes(so + 0x9db, r.randbytes(4))

    def code():
        return r.choice([0, 0, 0, 1, 5, 0x80000000, 0xffffffff, r.getrandbits(32)])

    def child_obj():
        slots = {0x2c: pystub(c, 2, ret=lambda em, k: code()),
                 0x34: pystub(c, 3, ret=lambda em, k: code()),
                 0x0c: pystub(c, 2, ret=lambda em, k: r.getrandbits(32)),
                 0x10: pystub(c, 4, ret=lambda em, k: code())}
        return obj(c, 0x40, slots)
    ch = child_obj() if r.random() < 0.85 else 0
    rc = code()

    def open_slot(em, res_):
        out = em.arg32(2)
        em.calllog.append(('open', em.arg32(0) != 0, em.arg32(1), out, em.arg32(3)))
        em.w32(out, ch)
        em.ret(eax=rc, argbytes=16)
    stream = obj(c, 0x20, {0x0c: e.stub_fn('open', open_slot)})
    this = e.alloc(0xc0, 4)
    e.wbytes(this, r.randbytes(0xc0))
    e.w32(this + 0x65, 0)   # 0x436060 is hooked anyway
    hook_rec(c, 0x436060, 1, this=True, pop=4, ret=1)
    hook_rec(c, 0x428960, 0, this=True, pop=0, ret=lambda em, k: r.choice([0, 0, 0, 1, r.getrandbits(32)]))
    if r.random() < 0.5:
        e.wbytes(this + 0x81, struct.pack('<I', r.randrange(0, 8)))
        e.wbytes(this + 0x85, struct.pack('<I', r.randrange(0, 0x14)))
    return [this, stream]


S(0x428fe0, 'GUESS load stream child object', 'thiscall', None, ret='al', gen=_g428fe0, note='batch38064')
