"""specs_u69_98.py - area 69, residue-8 (batch 98).
0x66d30b: thiscall, no args; loads pointer from self+0x20 (guess), checks non-null, calls ext_634273 (sized delete), clears slot.
"""
from pilot import S
from ckit import rnd

def _freeSlot(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x50)
    # Create distinct values at different offsets to verify offset sensitivity
    p_correct = self_ + 0x100
    p_wrong1 = self_ + 0x200
    p_wrong2 = self_ + 0x300

    # Correct offset: 0x40
    e.w32(self_ + 0x40, p_correct)
    # Decoys at nearby offsets
    e.w32(self_ + 0x3c, p_wrong1)
    e.w32(self_ + 0x44, p_wrong2)

    def hook(e, res):
        arg = e.arg32(0)
        if arg == p_correct:
            match = 2  # Correct
        elif arg == p_wrong1 or arg == p_wrong2:
            match = 0  # Wrong pointer
        else:
            match = 1  # Other
        e.calllog.append(('h634273', match, e.arg32(1)))
        e.ret(eax=0, argbytes=0)
    e.hook(0x634273, hook)
    return [self_]

S(0x66d30b, 'freeSlot66d30b (thiscall, sized delete from self+0x20)', 'thiscall', None, ret=None, gen=_freeSlot,
  note='u69 residue-8 batch 98; 0x634273 is a GUESS hook (sized delete, cdecl)')
