"""specs_s961.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): three wrappers (src/batch961.cpp). The callees are hooked by address
with recording stubs that log every argument: 0x42abee (cdecl, three arguments, returns a per-case value; claimed as its own row), 0x421080 (thiscall, no arguments; GUESS, its own row).
The stub returns are fixed per case, so the exe and the port see the same values."""
from pilot import S


def _rnd(c, n):
    return c.rng.getrandbits(32)


def _hook_cdecl3(c, addr, name, ret):
    def h(em, r):
        args = [em.arg32(k) for k in range(3)]
        c.emu.calllog.append((name, None, None, tuple(args)))
        em.ret(eax=ret, argbytes=0)
    c.emu.hook(addr, h)


def _hook_thiscall0(c, addr, name):
    def h(em, r):
        c.emu.calllog.append((name, None, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(addr, h)


def _gen_42fe00(c):
    _hook_cdecl3(c, 0x42abee, '42abee', c.rng.getrandbits(32))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen_421060(c):
    _hook_thiscall0(c, 0x421080, '421080')
    return [c.rng.getrandbits(32)]


S(0x42fe00, 'wrapper around 0x42abee (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen_42fe00,
  note='unclaimed-80 gap band; callee 0x42abee hooked by address (its own row)')
S(0x421060, 'GUESS wrapper around 0x421080 (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen_421060,
  note='unclaimed-80 gap band; callee 0x421080 hooked by address (GUESS); returns a1 in eax')
