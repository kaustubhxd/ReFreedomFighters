"""Relay-list command and timer, with REAL exe 0x4b8ab0 as callee (already
strict separately). Reuses a complete iterator/sink fixture, comparing every
iterator out word and forwarded receiver/id/message/payload. Control virtuals
are explicit logging stand-ins, not hidden hooks. No direct callee hooks."""
import struct, math
from pilot import S
from specs_s166001 import _gen as _list

def f32(x): return struct.unpack('<f', struct.pack('<f', x))[0]
def _fixture(c):
    me, payload = _list(c)
    em, r = c.emu, c.rng
    em.w32(me, em.logging_vtable('relay-list-control', 0x6c, argwords={0x64: 1, 0x68: 2}))
    delay = r.choice([0., -0., 0.5, 1., -1., r.uniform(-5, 5), float('nan'), float('inf')])
    stamp = f32(r.uniform(-20, 20))
    em.wf32(me + 0x50, delay); em.wf32(me + 0x54, stamp)
    eng = em.alloc(0x80, 4); em.wbytes(eng, bytes(0x80))
    threshold = f32(f32(stamp + f32(delay)) * 1024.)
    edge = int(threshold) if math.isfinite(threshold) and -2147483648 <= threshold < 2147483648 else -2147483648
    clock = r.choice([edge, edge - 1, edge + 1, r.randrange(-100000, 100000)])
    em.w32(eng + 0x40, clock & 0xffffffff); em.w32(0x70039c, eng)
    return me, payload

def _command(c):
    me, payload = _fixture(c)
    expected = (c.emu.r32(me + 0x48) & 0xffff)
    value = expected | (c.rng.getrandbits(16) << 16) if c.rng.random() < .75 else c.rng.getrandbits(32)
    return [me, value, payload]
def _frame(c): return [_fixture(c)[0]]
S(0x4b88f0, 'ZRelayMessageList::Command real strict dispatcher callee', 'thiscall', None, ret='eax', gen=_command,
  note='Real exe 0x4b8ab0 callee; iterator out words and sink arguments compared. Virtual scheduler logged with receiver and args.')
S(0x4b89d0, 'ZRelayMessageList::FrameUpdate real strict dispatcher callee', 'thiscall', None, ret=None, gen=_frame,
  note='Real exe 0x4b8ab0 callee; signed deadline ties and neighbors, float edge cases; iterator out words compared; virtual scheduler logged.')
