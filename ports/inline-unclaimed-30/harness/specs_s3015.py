"""specs_s3015.py - unclaimed-30 batch 15 (docs/20-unclaimed-30.md, claim 1): 0x4d2cd0 (no name in the name map). The object's slot 0xb0
(logged) returns a result object or 0; the result's data is at result + [result] + 0xc. The report goes to the debug reporter's
slot 0x24 (pfspec reporter, logged). memcpy is the exe's import: it is stubbed with a Python copy (cdecl, the same in both builds)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, log_args


def _memcpy(em, rr):
    dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
    em.wbytes(dst, em.rbytes(src, n))
    em.ret(eax=dst, argbytes=0)


def _u(c):
    e = c.emu
    r = c.rng
    e.stub_import('memcpy', _memcpy)
    # the debug object: its slot 0x24 is a cdecl report (logged with its arguments only; the exe's call leaves ECX at the vtable,
    # which a cdecl callee does not read, so ECX is not compared)
    def report(em, rr):
        em.calllog.append(('dbg', 0x24, tuple(log_args(em, 3, {}))))
        em.ret(argbytes=0)
    dbg = e.alloc(16)
    e.w32(dbg, e.fake_vtable('dbg', 0x40, {0x24: report}))
    e.w32(0x700390, dbg)
    if r.random() < 0.8:
        res = e.alloc(0x200)
        off = r.randint(0, 0x40)
        n = r.randint(0, 0x40)
        e.w32(res, off)
        e.w32(res + 8, n)
        q = e.alloc(0x20)
        e.w8(q + 0x10, r.getrandbits(8))
        e.w32(res + 4, q)
        e.wbytes(res + 0xc + off, bytes(r.getrandbits(8) for _ in range(n)))
    else:
        res = 0
    obj = rnd(c, 0x40)
    e.w32(obj, vtable(c, 'unn4d', 0x80, impl={0xb0: lambda em, a: res}, argwords={0xb0: 2}))
    dst = e.alloc(0x100)
    a1 = r.getrandbits(32)
    return [obj, a1, dst]


S(0x4d2cd0, 'unnamed 0x4d2cd0', 'thiscall', None, gen=_u, n=300)
