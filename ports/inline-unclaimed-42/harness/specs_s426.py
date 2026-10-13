"""specs_s426.py - unclaimed-42 batch 6 (claim 6): CRigidBody::Setup (0x53f5d0), thiscall, void.
The body has an object at +0x44 whose +8 is a block the helpers write into. That object is a logging vtable: slot +0x40
logs its call. The helpers (0x4dc630, 0x4db7c0, 0x6352a0) are original code run on zeroed blocks."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _setup(c):
    self_ = zero_obj(c, 0x400)
    blk = zero_obj(c, 0x200)
    sub = logged_obj(c, 'ZRigidSub', 0x100, impl={}, argwords={0x40: 0})
    c.emu.w32(sub + 8, blk)
    c.emu.w32(self_ + 0x44, sub)
    return [self_]


S(0x53f5d0, 'CRigidBody::Setup (unknown) thiscall', 'thiscall', None, ret=None, gen=_setup,
  note='unclaimed-42 batch 6; helpers 0x4dc630, 0x4db7c0, 0x6352a0 original; vtable +0x40 logged')
