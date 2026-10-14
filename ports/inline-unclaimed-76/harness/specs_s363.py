"""specs_s363.py - area 76, batch 363: five thiscall accessors with one stack argument (ret 4), see batch363.cpp.

Shared fixture: the holder (this+0x1c) has a vtable with slots 0x6a8 and 0x6b0 (thiscall, no arguments, returns a per-run value), +0x77f
(dword, read by 0x59ffc0), and +0x54 -> an object whose +4 is a value. The container (a+4 / a+8) is a struct S (S+0 = base, S+8 = count)
with C+0 = S, C+4 = 0, C+8 = 1 (or 0: the callback path). The element is base + 0; its flag byte (+4) is random over 0..2, so 0x5002f0's
log path runs in about two thirds of the cases (logger 0x700390, its slot 0x20 returns an object whose cdecl slot 0x2c is logged; the
callback 0x7003b0 is a stub). The exe helpers 0x59ffc0, 0x5003d0 and 0x5002f0 run as exe code."""
import struct
from pilot import S


def _gen_factory(addr_name, container_field):
    def _gen(c):
        e = c.emu
        rng = c.rng

        def cb(em, r):
            em.calllog.append(('cb', 0, None, ()))
            em.ret(eax=0, argbytes=0)

        e.w32(0x7003b0, e._new_stub('cb7003b0', cb))

        rv = {0x6a8: rng.getrandbits(32), 0x6b0: rng.getrandbits(32)}

        def mk_slot(off):
            def h(em, r):
                em.calllog.append(('holder', off, em.reg('ecx'), ()))
                em.ret(eax=rv[off], argbytes=0)
            return h

        hv = e.fake_vtable('holder', 0x6c0 // 4, {0x6a8: mk_slot(0x6a8), 0x6b0: mk_slot(0x6b0)})
        X = e.alloc(0x40, 4)
        e.w32(X + 4, rng.getrandbits(32))
        holder = e.alloc(0x1000, 4)
        e.wbytes(holder, rng.randbytes(0x1000))
        e.w32(holder, hv)
        e.w32(holder + 0x54, X)
        e.w32(holder + 0x77f, rng.getrandbits(32))

        # logger (0x700390): slot 0x20 is a thiscall stub with two arguments returning the report object; its slot 0x2c is cdecl
        rep_vt = e.fake_vtable('rep', 0x40 // 4 * 4, {0x2c: _rep2c})
        rep = e.alloc(0x40, 4)
        e.w32(rep, rep_vt)

        def log20(em, r):
            em.calllog.append(('log20', 0x20, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
            em.ret(eax=rep, argbytes=8)

        lg_vt = e.fake_vtable('logger', 0x40 // 4 * 4, {0x20: log20})
        lg = e.alloc(0x40, 4)
        e.w32(lg, lg_vt)
        e.w32(0x700390, lg)

        arr = e.alloc(0x100, 4)
        e.wbytes(arr, rng.randbytes(0x100))
        e.wbytes(arr + 4, bytes([rng.choice([0, 1, 2, 2])]))
        st = e.alloc(0x40, 4)
        e.w32(st, arr)
        e.w32(st + 8, rng.choice([16, 4, 0]))
        C = e.alloc(0x40, 4)
        e.w32(C, st)
        e.w32(C + 4, 0)
        e.w32(C + 8, rng.choice([1, 2, 0]))
        thisobj = e.alloc(0x40, 4)
        e.w32(thisobj + 0x1c, holder)
        a = e.alloc(0x20, 4)
        e.w32(a + 8, C)
        return [thisobj, a]
    return _gen


def _rep2c(em, r):
    em.calllog.append(('rep2c', 0x2c, None, tuple(em.arg32(k) for k in range(3))))
    em.ret(eax=0, argbytes=0)


S(0x55ace0, 'store55ace0 (GUESS)', 'thiscall', None, ret=None, gen=_gen_factory('55ace0', 'a8'),
  note='area 76 batch 363; label D; 0x59ffc0, 0x5003d0, 0x5002f0 run as exe code; logger and callback stubbed')
S(0x55b0f0, 'store55b0f0 (GUESS)', 'thiscall', None, ret=None, gen=_gen_factory('55b0f0', 'a8'),
  note='area 76 batch 363; label D')
S(0x559f30, 'store559f30 (GUESS)', 'thiscall', None, ret=None, gen=_gen_factory('559f30', 'a8'),
  note='area 76 batch 363; label D')
S(0x5595c0, 'store5595c0 (GUESS)', 'thiscall', None, ret=None, gen=_gen_factory('5595c0', 'a8'),
  note='area 76 batch 363; label D')
