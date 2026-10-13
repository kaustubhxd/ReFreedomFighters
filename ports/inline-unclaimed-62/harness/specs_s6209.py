"""specs_s6209.py - unclaimed-62 claim 4 (slice 1): 0x4d9190 (no name). The helpers 0x4d8db0 (key) and 0x4d8ef0 (lookup) are patched to logged
stubs returning per-case values (a found record or 0). The member object (first dword of the owner) has logged slots 8 and 4; the entry
object's slots 0x20 / 0x14 / 0 are logged. The sized free (0x634273) is the harness's. len is 0 (strlen) or the string's length."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _nlr(c):
    e = c.emu
    r = c.rng
    # the sized free (0x634273) reaches the CRT free import when the allocator global is null: a logged no-op (cdecl)
    e.stub_import('free', lambda em, rr: (em.calllog.append(('free',)), em.ret(argbytes=0))[1])
    key = r.getrandbits(32)
    found = e.alloc(16)
    e.w32(found, r.getrandbits(32))
    have_found = r.random() < 0.7

    def h4d8db0(em, rr):
        em.calllog.append(('4d8db0', em.arg32(0), em.arg32(1)))
        em.ret(eax=key, argbytes=8)

    def h4d8ef0(em, rr):
        em.calllog.append(('4d8ef0', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=found if have_found else 0, argbytes=12)
    ss.patch(c, 0x4d8db0, e.stub_fn('4d8db0', h4d8db0))
    ss.patch(c, 0x4d8ef0, e.stub_fn('4d8ef0', h4d8ef0))

    obj = rnd(c, 0x40)
    e.w32(obj, vtable(c, 'nlr_obj', 0x40, argwords={0x0: 1, 0x14: 0, 0x20: 1}))
    entry = rnd(c, 0x40)
    e.w32(entry + 0x11, r.choice([0, obj]))
    member = rnd(c, 0x40)
    entry_ret = entry if r.random() < 0.85 else 0
    e.w32(member, vtable(c, 'nlr_member', 0x40, impl={0x8: lambda em, a: entry_ret},
                         argwords={0x8: 2, 0x4: 1}))
    self_ = rnd(c, 0x40)
    e.w32(self_, member)
    e.w8(self_ + 4, r.choice([0, 1]))
    name = e.alloc(32)
    txt = bytes(r.choice(b'abcdef') for _ in range(r.randint(0, 12))) + b'\x00'
    e.wbytes(name, txt)
    ln = (len(txt) - 1) if r.random() < 0.5 else 0
    return [self_, name, ln]


S(0x4d9190, 'unnamed 0x4d9190', 'thiscall', None, gen=_nlr, n=1000)
