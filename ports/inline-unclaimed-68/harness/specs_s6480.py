"""specs_s6480.py - unclaimed-68 batch 48 (claim 48): ZSIGTE::HideAll (0x4a8d90). The head pointer is reached through the unaligned field +0x4e,
then the list head is at +0x50 of that block. Nodes are zeroed objects with next pointers at +0x60 (0..3 nodes). The engine's slot +0x50 returns a
random value, equal to the dword at this+0xbb in about one case in four. The helper 0x4db860 is exe code on each node."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _hide(c):
    o = zero_obj(c, 0x100)
    head = zero_obj(c, 0x80)
    n = c.rng.randrange(0, 4)
    nodes = [zero_obj(c, 0x100) for _ in range(n)]
    for i in range(n - 1):
        c.emu.w32(nodes[i] + 0x60, nodes[i + 1])
    c.emu.w32(head + 0x50, nodes[0] if n else 0)
    c.emu.w32(o + 0x4e, head)
    key = c.rng.getrandbits(32)
    c.emu.w32(o + 0xbb, key)
    ans = key if c.rng.random() < 0.25 else c.rng.getrandbits(32)
    en = logged_obj(c, 'ZSIGTEEngine', 0x80, impl={0x50: lambda e, a: (ans, None)}, argwords={0x50: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [o]


S(0x4a8d90, 'ZSIGTE::HideAll (unknown) thiscall', 'thiscall', None, ret=None, gen=_hide,
  note='unclaimed-68 batch 48; list through +0x4e/+0x50/+0x60; engine slot +0x50; helper 0x4db860 (exe) per node')
