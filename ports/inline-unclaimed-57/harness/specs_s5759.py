"""specs_s5759.py - unclaimed-57, batch 59: 0x5c7cb0 (GUESS name unnamed_5c7cb0). Thiscall, one unused stack argument (ret 4),
returns al = 1. Hooked callees: the assert hook at 0x7003b0 is a logging stub (always set, so the original's int3 branch is not
exercised); the readers 0x4e5ea0 and 0x4e5e40 are hooked to fixed results, because the original faults when they are called with
ecx = 0 (they dereference ecx). 0x4e5e40 returns its word in ax with random upper bits in eax, so a dword store would be caught."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    v48 = c.rng.getrandbits(32)
    v4c = c.rng.getrandbits(32)

    def assert_fn(em, r):
        em.calllog.append(('assert', 0, None, ()))
        em.ret(eax=0)
    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))
    e.hook(0x4e5ea0, lambda em, r: em.ret(eax=v48, argbytes=0))
    e.hook(0x4e5e40, lambda em, r: em.ret(eax=v4c, argbytes=0))
    self_obj = _rnd(c, 0x60)
    return [self_obj, c.rng.getrandbits(32)]


S(0x5c7cb0, 'unnamed_5c7cb0 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-57 batch 59; assert hook 0x7003b0 logs; readers 0x4e5ea0 and 0x4e5e40 hooked; returns 1')
