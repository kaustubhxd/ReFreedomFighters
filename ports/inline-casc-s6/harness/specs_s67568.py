"""specs_s67568.py - cascade s6 batch 67568 (0x615ae0, thiscall(v) ret 4, returns al of 0x65c3e0). The owner R = this[0x182a5] (slot 0x140; +0x1157 / +0x115b random pad dwords, +0x115f written, +0x1377 device
with COM-style slot 0xc8); sys slot 0x190 returns a logger object whose cdecl slot 0x184 (6 args) is a custom stub; 0x60ff30 / 0x60feb0 (fastcall, ecx edx + 2 stack args) are custom hooks; the flag 0x724948
and device 0x724a00 (slot 0xc8, stdcall 3 args via custom stub) vary; 0x65c3e0 is a hook returning a bool."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g615ae0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def l184(em, res_):
        em.calllog.append(('l184', tuple(em.arg32(i) for i in range(1, 6))))
        em.ret(eax=0, argbytes=0)
    X = obj(c, 0x20, {0x184: e.stub_fn('recorder', l184)})
    sysobj(c, slots={0x190: pystub(c, 0, this=True, ret=X)})

    def c8(tag):
        def h(em, res_):
            em.calllog.append((tag, em.arg32(0), em.arg32(1), em.arg32(2)))
            em.ret(eax=0, argbytes=12)
        return e.stub_fn('recorder', h)
    D = obj(c, 0x20, {0xc8: c8('dev1377')})
    dev2 = obj(c, 0x20, {0xc8: c8('dev724a00')})
    e.w32(0x724a00, dev2)
    e.w32(0x724948, r.choice([0, 1, 5]))

    def fc(addr):
        def h(em, res_):
            em.calllog.append((hex(addr), em.reg('ecx'), em.reg('edx'), em.arg32(0), em.arg32(1)))
            em.ret(eax=0, argbytes=8)
        e.hook(addr, h)
    fc(0x60ff30)
    fc(0x60feb0)
    hook_rec(c, 0x65c3e0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))
    R = obj(c, 0x1400, {0x140: pystub(c, 0, this=True)})
    _w(c, R + 0x1377, D)
    _w(c, R + 0x1157, r.choice([0, 1, 2, 3, r.getrandbits(32)]))
    _w(c, R + 0x115b, r.choice([0, 1, 2, 3, r.getrandbits(32)]))
    t = rnd(c, 0x18300)
    _w(c, t + 0x182a5, R)
    return [t, r.getrandbits(32)]


S(0x615ae0, 'GUESS refresh_pad_state', 'thiscall', None, ret='al', gen=_g615ae0, note='batch67568')
