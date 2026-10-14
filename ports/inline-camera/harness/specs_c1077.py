"""specs_c1077.py - camera batch 1077: ZCameraViewEntry::Update (0x64de00). The source is a block of random words that covers
the offsets read (up to +0x18259)."""
from pilot import S
from camgen import rnd


def _view(c):
    self_ = rnd(c, 0x100)
    src = rnd(c, 0x18300)
    return [self_, src]


S(0x64de00, 'ZCameraViewEntry::Update', 'thiscall', gen=_view)
