"""specs_s730.py - soldier AI batch 730: CActorActionMarker::Add. The marker object holds a count of 0..16 and 16 record
pointers (each record 0x18 bytes of random content), so the append path always has a record to write. The argument object
is either the first dword of an existing record (the update path) or a fresh value (the append path). The type is one of
0..3 and the time is random in about [-3, 3]; the flag, the copied old time and the zeroed fields are all compared through
the heap."""
import struct
from pilot import S
from specs_s701 import _rnd


def _add(c):
    e = c.emu
    self_ = _rnd(c, 0x100)
    recs = []
    for i in range(16):
        r = _rnd(c, 0x18)
        e.w32(r, 0x2000 + i * 0x10)      # unique first dword (the object tag)
        recs.append(r)
    for i, r in enumerate(recs):
        e.w32(self_ + 4 + 4 * i, r)
    n = c.rng.choice([0, 1, 2, 3, 5, 8, 15, 16])
    e.w32(self_ + 0x44, n)
    if n and c.rng.random() < 0.6:
        obj = 0x2000 + c.rng.randrange(n) * 0x10
    else:
        obj = 0x90000000 | c.rng.getrandbits(16)
    typ = c.rng.choice([0, 1, 2, 3])
    t = struct.unpack('<f', struct.pack('<f', c.rng.uniform(-3.0, 3.0)))[0]
    tbits = struct.unpack('<I', struct.pack('<f', t))[0]
    return [self_, obj, typ, tbits]


S(0x5eab20, 'CActorActionMarker::Add', 'thiscall', None, ret=None, gen=_add,
  note='b730 [medium]; time passed as its float bits (stack argument)')
