"""specs_s1021.py - unclaimed-04 batch 22 (docs/20-unclaimed-04.md): three slice-3 functions (GUESS labels).
0x533bb0 returns ResetEvent(*0x701b6c) and 0x54ab30 returns SetEvent(*0x701b6c); both IAT imports are Python stubs that
return a per-case value (logged). 0x549370 stores vtable 0x6a3338 and tail-jumps to 0x54cd00 (original code)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup_events(c):
    c.emu.w32(0x701b6c, c.rng.getrandbits(32))
    val_reset = c.rng.choice([0, 1])
    val_set = c.rng.choice([0, 1])

    def reset(em, r):
        em.calllog.append(('ResetEvent', 0, 0, (em.arg32(0),)))
        em.ret(eax=val_reset, argbytes=4)

    def set_(em, r):
        em.calllog.append(('SetEvent', 0, 0, (em.arg32(0),)))
        em.ret(eax=val_set, argbytes=4)

    c.emu.stub_import('ResetEvent', reset)
    c.emu.stub_import('SetEvent', set_)


def _none(c):
    return []


def _obj(c):
    return [_rnd(c, 0x100)]


S(0x533bb0, 'unknown::reset_global_event (unknown) cdecl', 'cdecl', None, ret='eax', gen=_none, setup=_setup_events,
  note='unclaimed-04 batch 22; ResetEvent import stubbed (GUESS)')
S(0x54ab30, 'unknown::set_global_event (unknown) cdecl', 'cdecl', None, ret='eax', gen=_none, setup=_setup_events,
  note='unclaimed-04 batch 22; SetEvent import stubbed (GUESS)')
S(0x549370, 'unknown::set_vtable_6a3338_tail_54cd00 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-04 batch 22; tail-calls original 0x54cd00 (vtable 0x6a3e14)')
