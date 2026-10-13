"""specs_s912.py - unclaimed-09 batch 4 (docs/20-unclaimed-09.md, claim 4): ZActivateBinoculars::Command.

Stub (unverified callee): obj's vtable slot +0x88 is a fake, logged slot. Its log entry is (name, 0x68884c, cmd word
read through the pointer argument); the pointer itself is not logged, since the stack address differs between the
exe and the port. Object self: 0x1000 random bytes, with the word at +0x48 set to the command's low word in about half
the cases so the branch is taken. obj is null in about one case in eight."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot88(e, r):
    a = e.arg32(0)
    p = e.arg32(1)
    word = int.from_bytes(e.rbytes(p, 2), 'little')
    e.calllog.append(('Slot88', a, word))
    e.ret(eax=0, argbytes=8)


def _gen(c):
    obj_self = _rnd(c, 0x1000)
    cmd = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        c.emu.w16(obj_self + 0x48, cmd & 0xffff)
    else:
        c.emu.w16(obj_self + 0x48, c.rng.getrandbits(16))
    if c.rng.random() < 0.125:
        obj = 0
    else:
        obj = c.emu.fake_object('binoc_obj', 0x40, slots={0x88: _slot88})
    return [obj_self, cmd, obj]


S(0x4c9300, 'ZActivateBinoculars::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-09 b4; stub: obj slot +0x88 logged (unverified callee)')
