"""specs_s913.py - unclaimed-09 batch 5 (docs/20-unclaimed-09.md, claim 5): ZActionReloadItem::Load(ZLoadGame&).

Stubs (unverified callees, all logged or observable):
- the ZLoadGame stand-in (serial_stubs.load_obj): slot 0x50 is a logged rec (argument = this+0x30, a heap pointer);
  slot 0x68 writes a flag byte (0 or 1, random per case) through its pointer argument; slot 0x40 writes a dword
  (random per case) through its pointer argument.
- the item's own vtable slot 0x2c: a logged rec that returns a random dword, stored at this+0x2c by the exe.
The item object is 0x100 random bytes; its vtable is the only thing the spec fills in besides the stub addresses."""
from pilot import S
import random
from serial_stubs import mkobj, rec, wr, load_obj

def _gen(c):
    flag = c.rng.getrandbits(1)
    n = c.rng.getrandbits(32)
    ret = c.rng.getrandbits(32)
    ld = load_obj(c, {0x50: rec(c, 1), 0x68: wr(c, 1, 0, 1, flag), 0x40: wr(c, 1, 0, 4, n)})
    item = mkobj(c, {0x2c: rec(c, 1, ret=ret)}, size=0x100)
    return [item, ld]


S(0x486dc0, 'ZActionReloadItem::Load (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b5; stubs: ZLoadGame slots 0x50/0x68/0x40 and item slot 0x2c (unverified callees)')
