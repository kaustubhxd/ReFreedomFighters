"""specs_s1958.py - unclaimed-66 batch 68 (gap band, GUESS name). Cdecl, no arguments, returns eax.

0x41e290 (the allocator: an indirect jump through a runtime pointer, so hooked by address; cdecl, one argument) returns a fresh zeroed
12-byte block or 0, chosen in gen. 0x50b420 (THISCALL, no arguments; an SEH-framed init, hooked by address) logs ECX. The global 0x7011fc is
either 0 or a logging object whose +0x24 slot returns a fixed value."""
from pilot import S


def _gen(c):
    rv24 = c.rng.getrandbits(32)

    def h24(e, r):
        e.calllog.append(('singleton vtable +0x24 (stub)', 0x24, e.reg('ecx'), ()))
        e.ret(eax=rv24, argbytes=0)
    if c.rng.random() < 0.5:
        obj = 0
    else:
        vt = c.emu.fake_vtable('batch68 obj', 0x24 // 4 + 1, slots={0x24: h24})
        obj = c.emu.fake_object('batch68 obj', 0x40, vtable=vt)
    c.emu.w32(0x7011fc, obj)

    fresh = 0 if c.rng.random() < 0.2 else c.emu.alloc(0xc)

    def h41(e, r):
        e.calllog.append(('0x41e290 allocator (GUESS stub)', 0x41e290, None, (e.arg32(0),)))
        e.ret(eax=fresh, argbytes=0)
    c.emu.hook(0x41e290, h41)

    def h50b(e, r):
        e.calllog.append(('0x50b420 (GUESS stub)', 0x50b420, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x50b420, h50b)
    return []


S(0x50b620, 'GUESS FUN_0050b620 (singleton getter: vtable +0x24 when set, else 0x41e290 alloc and 0x50b420)', 'cdecl', None,
  ret='eax', gen=_gen, note='unclaimed-66 batch 1958; gap band; 0x41e290 and 0x50b420 GUESS stubs by address')
