"""specs_s920.py - unclaimed-09 batch 12 (docs/20-unclaimed-09.md, claim 12): 0x4a1300 (named CAction::SafeDelete, low;
the body is an initialiser).

The object is a fake object with vtable slots 0x88 (two arguments) and 0xa8 (one argument), both logged Python
handlers (unverified callees); the rest of the object is random bytes. Eight arguments are random 32-bit values;
the word store takes only the low 16 bits. The callee pops its own arguments (thiscall ret 8 and ret 4)."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng

    def h88(e2, r):
        e2.calllog.append(('Slot88', e2.arg32(0), e2.arg32(1)))
        e2.ret(eax=0, argbytes=8)

    def ha8(e2, r):
        e2.calllog.append(('Slot a8', e2.arg32(0)))
        e2.ret(eax=0, argbytes=4)

    obj = e.fake_object('caction', 0x110, slots={0x88: h88, 0xa8: ha8})
    e.wbytes(obj + 4, bytes(rng.getrandbits(8) for _ in range(0x110 - 4)))
    args = [rng.getrandbits(32) for _ in range(8)]
    return [obj] + args


S(0x4a1300, 'CAction::SafeDelete (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b12; name low and does not match the body; vt 0x88/0xa8 stubbed (unverified callees)')
